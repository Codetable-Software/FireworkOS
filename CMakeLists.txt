cmake_minimum_required(VERSION 3.20)
project(FireworkOS C CXX ASM)
option(FIREWORK_HOST_SIM "Build native x86_64 host simulator" OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wdouble-promotion -Wformat=2 -Werror=format-security)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/arch/include ${CMAKE_SOURCE_DIR}/modules/include)
if(FIREWORK_HOST_SIM)
  add_compile_definitions(FIREWORK_HOST_SIM=1)
  add_library(fireworker_core
    kernel/init/kinit.c kernel/sched/scheduler.c kernel/sched/task.c kernel/sched/idle.c
    kernel/mm/heap.c kernel/mm/pool_allocator.c kernel/mm/mpu_protect.c
    kernel/ipc/queue.c kernel/ipc/semaphore.c kernel/ipc/mutex.c kernel/ipc/signal.c
    kernel/syscall/syscall.c kernel/syscall/sys_table.c
    drivers/core/device.c drivers/core/driver.c drivers/core/bus.c
    modules/loader/elf_loader.c modules/loader/reloc.c modules/loader/symtab.c
    lib/libc/string.c lib/libc/printf.c lib/libc/stdlib.c lib/libc/ctype.c
    fs/vfs/vfs.c fs/vfs/vfs_file.c fs/vfs/vfs_dev.c
    net/core/net_buf.c net/core/net_socket.c
    user/shell/fw_shell.c user/shell/commands.c
  )
  add_executable(firework_sim kernel/init/main.c)
  target_link_libraries(firework_sim PRIVATE fireworker_core)
  enable_testing()
  add_executable(test_mm tests/unit/test_mm.c)
  add_executable(test_queue tests/unit/test_queue.c)
  add_executable(test_elf_loader tests/unit/test_elf_loader.c)
  add_executable(test_driver_load tests/integration/test_driver_load.c)
  foreach(t test_mm test_queue test_elf_loader test_driver_load)
    target_link_libraries(${t} PRIVATE fireworker_core)
    add_test(NAME ${t} COMMAND ${t})
  endforeach()
else()
  message(STATUS "Cross target selected: provide architecture/toolchain flags externally")
  add_library(firework_baremetal OBJECT
    kernel/init/kinit.c kernel/sched/scheduler.c kernel/sched/task.c kernel/mm/heap.c
    kernel/ipc/queue.c kernel/ipc/mutex.c kernel/syscall/syscall.c
    lib/libc/string.c lib/libc/printf.c lib/libc/stdlib.c
  )
  target_compile_options(firework_baremetal PRIVATE -ffreestanding -fno-builtin -fno-exceptions -fno-rtti)
endif()

# FireworkOS

FireworkOS is a modular bare-metal RTOS/kernel prototype centered on the `fireworker` kernel. The repository includes native host simulation, memory/IPC tests, ELF validation, and architecture ports.

## Host build

`cmake -B build -DFIREWORK_HOST_SIM=ON`

`cmake --build build`

`ctest --test-dir build --output-on-failure`

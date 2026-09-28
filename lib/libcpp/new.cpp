#include <new>
void* operator new(std::size_t n){return ::malloc(n);} void* operator new[](std::size_t n){return ::malloc(n);} void operator delete(void*p) noexcept{::free(p);} void operator delete[](void*p) noexcept{::free(p);}

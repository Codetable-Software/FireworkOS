#pragma once
#include <cstddef>
namespace fw { class string { const char* p_; public: explicit string(const char* p=""):p_(p){} const char* c_str() const{return p_;} }; }

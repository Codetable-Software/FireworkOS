#pragma once
#include <cstddef>
namespace fw { template<class T,size_t N> class vector { T a_[N]{}; size_t n_=0; public: bool push_back(const T&v){if(n_>=N)return false;a_[n_++]=v;return true;} size_t size()const{return n_;} T& operator[](size_t i){return a_[i];} }; }

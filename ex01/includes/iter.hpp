#ifndef iter_H
#define iter_H

#include <cstddef>
#include <iostream>
#include "Utils.hpp"

template<typename T>
void print(const T& value) {
    std::cout << value << " ";
}

template<typename T, typename Func>
void iter(T* array, size_t length_of_array, Func func)
{
    size_t i = -1;
    while (++i < length_of_array)
        func(array[i]);
}   

#endif
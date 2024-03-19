#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.hpp"

template<typename T> class Array
{
    private:
        T* elements;
        unsigned int arraySize;

    public:
        Array(void) : elements(NULL), arraySize(0) {
            std::cout << CYAN DEFAULT_CONSTRUCTOR RESET << std::endl;
        }

        Array(unsigned int const n) : elements(new T[n]), arraySize(n) {
            std::cout << CYAN PARAMTER_CONSTRUCTOR RESET << std::endl;
            unsigned int i = -1;
            while (++i < n)
                elements[i] = T();
        }

        Array(const Array& other) : elements(new T[other.arraySize]), arraySize(other.arraySize) {
            std::cout << CYAN COPY_CONSTRUCTOR RESET << std::endl;
            unsigned int i = -1;
            while (++i < arraySize)
                elements[i] = other.elements[i];
            }

        Array<T>& operator=(const Array& other) {
            std::cout << CYAN ASSIGMENT_OPERATOR RESET << std::endl;
            if (this != &other) {
                delete[] elements;
                arraySize = other.arraySize;
                elements = new T[arraySize];
                unsigned int i = -1;
                while (++i < arraySize)
                    elements[i] = other.elements[i];
            }
            return *this;
        }

        ~Array() {
            std::cout << CYAN DESTRUCTOR RESET << std::endl;
            delete[] elements;
        }

        T& operator[](unsigned int index) {
            if (index >= arraySize) {
                std::cout << RED FAILURE RESET << std::endl;
                throw std::out_of_range(RED "Index out of bounds" RESET);
            }
            return elements[index];
        }

        unsigned int size() const {
            return arraySize;
        }
};

#endif 
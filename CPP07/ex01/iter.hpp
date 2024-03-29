#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T, typename P>
void iter(T *array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(T *array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
#include <vector>

template <typename T>
void easyfind(T &a, int b) {
    typename T::const_iterator found = std::find(a.cbegin(), a.cend(), b);
    if (found  == a.cend())
    {
        throw(std::runtime_error("Not Found"));
    }
    std::cout << *(std::find(a.cbegin(), a.cend(), b));
}

#endif
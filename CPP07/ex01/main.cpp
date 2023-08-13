#include "iter.hpp"

template <typename T>
void displayElement(T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {0.1, 0.2, 0.3, 0.4, 0.5};

    std::cout << "Int array elements: ";
    ::iter(intArray, sizeof(intArray) / sizeof(intArray[0]), displayElement<int>);
    std::cout << std::endl;

    std::cout << "Double array elements: ";
    ::iter(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]), displayElement<double>);
    std::cout << std::endl;

    return 0;
}
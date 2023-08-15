#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
    T *_array;
    size_t _size;
public:
    Array() {
        _array = NULL;
        _size = 0;
    };
    Array(unsigned int n) {
        _array = new T[n]; 
        for (size_t i = 0; i < n; i++)
        {
            _array[i] = 0;
        }
        _size = n;        
    };
    
    Array(Array<T> const &obj) {
        _array = new T[obj.size()];
        _size = obj.size();
        for (size_t i = 0; i < obj.size(); i++)
        {
            _array[i] = obj._array[i];
        }
    };


    Array &operator=(Array<T> const &obj) {
        delete[] _array;
        _array = new T[obj.size()];
        _size = obj.size();
        for (size_t i = 0; i < obj.size(); i++)
        {
            _array[i] = obj._array[i];
        }
    };

    T &operator[](size_t index) {
        if (index >= _size)
            throw std::out_of_range("index is out of bounds");
        return (_array[index]);
    };

    ~Array() {
        delete[] _array;
    };

    size_t size() const { 
        return _size;
    };
};


#endif
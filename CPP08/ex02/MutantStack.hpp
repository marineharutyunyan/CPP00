#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator iterator;

        MutantStack() : std::stack<T, std::deque<T> >() {};

        MutantStack(const MutantStack &obj) :  std::stack<T, std::deque<T> >(obj) {}

        MutantStack &operator=(const MutantStack &obj)
        {
            if (this != &obj)
            {
                std::stack<T, std::deque<T> >::operator=(obj);
            }
            return *this;
        }

        ~MutantStack() {};
        
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};


#endif
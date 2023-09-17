#include <iostream>
#include <vector>
#include<list>
#include <cmath> 

    
class PmergeMe
{
private:
    std::vector<int> _dataVector;
    std::list<int> _dataList;
public:
    PmergeMe();
    template <typename It>
    PmergeMe(It begin, It end) 
    : _dataVector(begin, end), _dataList(begin, end) { };
    ~PmergeMe();
    void sort();
    void sort_2();
    void fillContainer(int N);
};


bool legal_int(char *str);
double	get_time();
template <typename T>
void printContainer(T data);

template <typename T>
void swap(T &a, T &b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}


template <typename It>
void insertionSort(It begin, It end)
{

    It indexI = begin;
    begin--;  
    std::advance(indexI, 1);
    while (indexI != end)
    {
        It current = indexI;
        It indexJ = current;
        indexJ--;

        while( indexJ != begin && *current < *indexJ)
        {
            swap(*current, *indexJ);
            current--;
            indexJ--;
        }
        ++indexI;
    }
    
}

template <typename T>
void printContainer(T data)
{
    for (typename T::iterator it = data.begin(); it != data.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}


template <typename Cont>
Cont  merge(typename Cont::iterator Lbegin, typename Cont::iterator Rbegin, typename Cont::iterator Lend, typename Cont::iterator Rend)
{
    Cont vector;

    while (Rbegin != Rend && Lbegin != Lend)
    {
        if (*Lbegin > *Rbegin)
        {
            vector.push_back(*Rbegin);
            Rbegin++;
            if(Rbegin == Rend)
            {
                while (Lbegin != Lend)
                {
                    vector.push_back(*Lbegin);
                    Lbegin++;
                }
            }
        }
        else
        {
            vector.push_back(*Lbegin);
            Lbegin++;
            if(Lbegin == Lend)
            {
                while (Rbegin != Rend)
                {               
                    vector.push_back(*Rbegin);
                    Rbegin++;
                }
            }
        }
    }
    return(vector);
}

template <typename Cont>
Cont recurciveSort(typename Cont::iterator begin, typename Cont::iterator end)
{
        int size = std::distance(begin, end);
        size_t n1;
        size_t n2;
        n1 = size / 2;
        n2 = std::ceil(size / 2);
        // if (size % 2 == 0)
        //     n2 = size/2;
        // else 
        //     n2 = (size/2) + 1;
        Cont L;
        Cont R;
        if (size <= 44) {
            insertionSort(begin, end);
            return Cont(begin, end);
        }
        typename Cont::iterator middle = begin;
        std::advance(middle, n1);
        L = recurciveSort<Cont>(begin, middle);
        R = recurciveSort<Cont>(middle, end);
        return merge<Cont>(L.begin(), R.begin(), L.end(), R.end());
}


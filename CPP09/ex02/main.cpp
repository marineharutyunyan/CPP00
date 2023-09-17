#include"PmergeMe.hpp"


bool legal_int(char *str)
{
    int i = 0;
    while (str[i] != 0)
    {    
        if (str == NULL || str[i] == '\0') {
            return false;
        }
        if (!std::isdigit(str[i])) {
           return false;
        }
        long long num = std::atoll(str);
        if (num > INT_MAX) {
            throw std::logic_error("Out of Int limits");
        }
        i++;
    }
    return true;
}
template <typename T>
void printVector (T data)
{
    std::cout << "Size : " << data.size() << std::endl;
    if (data.empty() == true)
        std::cout << "Vector is empty" << std::endl;
    else 
    {
        std::cout << "Vector elements are: " << std::endl;
    }

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
        n1 = size/2;
        if (size % 2 == 0)
            n2 = size/2;
        else 
            n2 = (size/2) + 1;
        Cont L;
        Cont R;
        if (size <= 1) {
            return Cont(begin, end);
        }
        typename Cont::iterator middle = begin;
        std::advance(middle, n1);
        L = recurciveSort<Cont>(begin, middle);
        R = recurciveSort<Cont>(middle, end);
        return merge<Cont>(L.begin(), R.begin(), L.end(), R.end());
}

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


int main (/*int argc, char **argv*/)
{
    try
    {
        //if(argc >= 2)
        // {
            // std::vector<int> data;
            std::list<int> data;
            data.push_back(27);
            data.push_back(38);
            data.push_back(2);
            data.push_back(3);
            data.push_back(16);

            // for (int i = 1; i <= argc-1; i++)
            // {
            //     if (legal_int(argv[i]))
            //         data.push_back(std::atoi(argv[i]));
            //     else 
            //         throw std::logic_error("Invaled numbers sequance");
            // }            
            // printVector(data);

            //printVector();
            //data = recurciveSort<std::list<int> >(data.begin(), data.end());
            insertionSort(data.begin(), data.end());
            printVector(data);

        // }
        // else 
        // {
        //     std::cerr << "Error" << std::endl; 
        // }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
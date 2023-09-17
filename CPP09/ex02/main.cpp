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

template <typename It>
std::vector<int> fillArray(size_t n, It it)
{
    std::vector<int> vector;
    
    for (size_t i = 0; i < n; i++)
    {
        vector.push_back(*it);
        it++;    
    }
    return(vector);
}

void printVector (std::vector<int> data)
{
    std::cout << "Size : " << data.size() << std::endl;
    if (data.empty() == true)
        std::cout << "Vector is empty" << std::endl;
    else 
    {
        std::cout << "Vector elements are: " << std::endl;
    }

    for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
} 

template <typename It>
std::vector<int>  merge(It Lbegin, It Rbegin, It Lend, It Rend)
{
    std::vector<int> vector;
    while (Rbegin != Rend && Lbegin != Lend)
    {
        std::cout << "In if socpe compareing " << *Lbegin << " and " <<*Rbegin << std::endl;
        if (*Lbegin > *Rbegin)
        {
            vector.push_back(*Rbegin);
            Rbegin++;
            if(Rbegin == Rend)
            {
                vector.push_back(*Lbegin);
                Lbegin++;
            }
        }
        else 
        {
            vector.push_back(*Lbegin);
            Lbegin++;
            if(Lbegin == Lend)
            {
                vector.push_back(*Rbegin);
                Rbegin++;
            }
        }
    }
    return(vector);
}

template <typename It>
void recurciveSplit(It begin, It end, size_t size)
{
        size_t n1;
        size_t n2;
        n1 = size/2;
        if (size % 2 == 0)
            n2 = size/2;
        else 
            n2 = (size/2) + 1;
        std::cout << "Splited array sizes are " << n1 << " " << n2 << std::endl;
        std::vector<int> L;
        std::vector<int> R;
        if (size == 2)
        {
            std::vector<int> mergedVector;
            std::cout << "reached till the last element is " << *begin << std::endl;
            L = fillArray(n1, begin);
            printVector(L);

            R = fillArray(n2, begin+n1);
            printVector(R);
            mergedVector = merge(L.begin(), R.begin(), L.end(), R.end());
            printVector(mergedVector);
            std::cout << "here \n";
        }
        else 
        {

            L = fillArray(n1, begin);
            recurciveSplit(L.begin(), L.end(), L.size());
            //printVector(L);

            // R = fillArray(n2, begin+n1);
            // recurciveSplit(R.begin(), R.end(), R.size());
            // printVector(R);
        }    
}

int main ()
{
    std::vector<int> data;
    data.push_back(38);
    data.push_back(27);
    data.push_back(2);
    data.push_back(3);
    data.push_back(16);

  
    printVector(data);

    recurciveSplit(data.begin(), data.end(), data.size());
    return 0;
}





// int main (/*int argc, char **argv*/)
// {
//     try
//     {
//         // if(argc >= 2)
//         // {
//             std::vector<int> data;
//             data.push_back(7);
//             data.push_back(2);
//             data.push_back(3);

//             // for (int i = 1; i <= argc-1; i++)
//             // {
//             //     if (legal_int(argv[i]))
//             //         data.push_back(std::atoi(argv[i]));
//             //     else 
//             //         throw std::logic_error("Invaled numbers sequance");
//             // }
//             std::cout << "Size : " << data.size() << std::endl;
//             if (data.empty() == false)
//                 std::cout << "Vector is not empty" << std::endl;
//             else
//                 std::cout << "Vector is empty" << std::endl;
//             std::cout << "Vector elements are: " << std::endl;

//             //splitArr(data.begin(), data.end(), data.size());
//             for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
//                 std::cout << *it << " ";
//             std::cout << std::endl;
//         // }
//         // else 
//         // {
//         //     std::cerr << "Error" << std::endl; 
//         // }
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }
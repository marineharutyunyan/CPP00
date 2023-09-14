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
    std::vector<int> vector(n);
    for (int i = 0; i <= n; i++)
    {
        vector.push_back(*it);
        it++;
    }
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    return(vector);
}

template <typename It>
void mergeSort1(It begin, It end, size_t size)
{
    size_t n1;
    size_t n2;
    n1 = size/2;
    if (size % 2 == 0)
        n2 = size/2;
    else 
        n2 = (size/2) + 1;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    L = fillArray(n1, begin);
    R = fillArray(n2, begin+n1);
}

int main (int argc, char **argv)
{
    try
    {
        if(argc >= 2)
        {
            std::vector<int> data;
        
            for (int i = 1; i <= argc-1; i++)
            {
                if (legal_int(argv[i]))
                    data.push_back(std::atoi(argv[i]));
                else 
                    throw std::logic_error("Invaled numbers sequance");
            }
            std::cout << "Size : " << data.size() << std::endl;

            // if (data.empty() == false)
            //     std::cout << "Vector is not empty" << std::endl;
            // else
            //     std::cout << "Vector is empty" << std::endl;
                
            // std::cout << "Vector elements are: " << std::endl;
            mergeSort1(data.begin(), data.end(), data.size());
            // for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
            //     std::cout << *it << " ";
            // std::cout << std::endl;
        }
        else 
        {
            std::cerr << "Error" << std::endl; 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
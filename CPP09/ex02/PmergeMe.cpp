#include "PmergeMe.hpp"
#include <unistd.h>
# include <sys/time.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj) :  _dataVector(obj._dataVector), _dataList(obj._dataList)  {};

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    if (this != &obj) {
        _dataList = obj._dataList;
        _dataVector = obj._dataVector;
    }
    return (*this);
};

void PmergeMe::sort()
{
        std::cout << "Before:  ";
        printContainer<std::list<int> >(_dataList);
        double start_time = get_time();
        recurciveSort<std::list<int> >(_dataList.begin(), _dataList.end());
        double end_time = get_time();;
        std::cout << "After:   ";
        printContainer<std::list<int> >(_dataList);
        std::cout << "Time to process a range of  " << _dataList.size() << " elements with std::list : " << end_time - start_time << " us" << std::endl;
        start_time = get_time();
        recurciveSort<std::vector<int> >(_dataVector.begin(), _dataVector.end());
        end_time = get_time();;
        std::cout << "Time to process a range of  " << _dataVector.size() << " elements with std::vector : " << end_time - start_time << " us" << std::endl;       
}

void PmergeMe::fillContainer(int N) {
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> v(N);
    std::generate(v.begin(), v.end(), std::rand);
    _dataVector.assign(v.begin(), v.end());
    _dataList.assign(v.begin(), v.end());
};

bool legal_int(char *str)
{
    int i = 0;
    if (str == NULL) {
        return false;
    }
    while (str[i] != 0)
    {
        if (!std::isdigit(str[i])) {
            return false;
        }
        i++;
    } 
    long long num = std::atoll(str);
    if (num > INT_MAX) {
        throw std::logic_error("Out of Int limits");
    }
    return true;
}

double	get_time()
{
	struct timeval	current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000) + (current_time.tv_usec);
}
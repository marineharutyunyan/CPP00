#include"Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
    nums.reserve(N);
}

void Span::addNumber(int num)
{
    if (nums.size() == _N)
    {
        throw(std::out_of_range(std::string("there are already ") + std::to_string(_N) + std::string(" elements in the list, can't add more")));
    }
    nums.push_back(num);
}

int Span::shortestSpan()
{
    int distance = *(std::max_element(nums.begin(), nums.end()));
    if (nums.size() < 2)
    {
        throw(std::logic_error(std::string("no span can be found.")));
    }
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 1; i++)
    {

        int tmepDistance = nums[i+1] - nums[i];
        if(tmepDistance < distance)
        {
            distance = tmepDistance;    
        }        
    }
    return (distance);
}

int Span::longestSpan()
{
    int distance;
    if(nums.size() < 2)
    {
        throw(std::logic_error(std::string("no span can be found.")));
    }
    std::vector<int>::iterator min = std::min_element(nums.begin(), nums.end());
    std::vector<int>::iterator max = std::max_element(nums.begin(), nums.end());
    distance = *max - *min;
    return (distance);
}

Span::~Span()
{

}

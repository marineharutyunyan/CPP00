#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
    #include <vector>

class Span
{
private:
    unsigned int _N;
    std::vector<int> nums;
public:
//TODO make class ortodox
    Span(unsigned int N);
    ~Span();
    void addNumber(int n);
    template<typename T>
    void fillSpan(T begin, T end)
    {
        while (begin < end)
        {
            addNumber(*begin);
            begin++;
        }
    }
    int shortestSpan();
    int longestSpan();
};

#endif
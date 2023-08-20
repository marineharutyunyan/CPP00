#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
#include <cstring>
#include <cctype>

class RPN
{
    private:
        static  std::stack<int> myStack;
        static int exec(int a, int b, char op);
        static bool isValidExpression(char *argv);
    public:
        RPN &operator=(const RPN &obj);
        static void calculate(char *str);
        RPN();
        RPN(const RPN &obj);
        ~RPN();
};

#endif

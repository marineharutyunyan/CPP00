#include "RPN.hpp"

std::stack<int> RPN::myStack;

RPN::RPN() {};

RPN::RPN(const RPN &obj) { (void)obj;};

RPN::~RPN() {};

RPN &RPN::operator=(const RPN &obj) {
    (void)obj;
    return (*this);
};

bool RPN::isValidExpression(char *argv)
{
    int i = 0;
    if(std::string(argv).length() != 1)
    {
        return(false);
    }
    if(!(std::isdigit(argv[i]) || argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/'))
    {
        return false;
    }
    return true;
}

int RPN::exec(int a, int b, char op)
{
    if(op == '+')
    {
        return(a + b);
    }
    else if(op == '-')
    {
        return(a - b);
    }
    else if(op == '*')
    {
        return(a * b);
    }
    return(a / b);
}
void RPN::calculate(char *str)
{
    char *token = std::strtok(str, " ");

    while (token != NULL) {
        if(RPN::isValidExpression(token))
        {
            if(std::isdigit(token[0]))
            {
                myStack.push(atoi(token));
            }
            else if(myStack.size() >= 2)
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();               
                myStack.push(exec(b, a, token[0]));
            } else {
                throw std::logic_error("less than two numbers");
            }
            token = std::strtok(nullptr, " ");
        }
        else
        {
           throw std::logic_error("inValidExpression");;
        }
    }
    if (myStack.empty() == false)
    {
        std::cout << myStack.top() << std::endl;
    } else {
        throw std::logic_error("Error");;
    }
}
#include "ScalarConverter.hpp"

bool isDisplayable(int value) {
    if (value >= 32 && value <= 126) {
        return true;
    }
    return false;
}

bool is_int(std::string literal)
{
    int i = 0;
    if(literal[0] == '-')
    {
        i++;
    }
    while(literal[i])
    {
        if(literal[i] >= 48 && literal[i] <= 57)
          i++;
        else
         return (false);
    }

    return(true);
}

bool is_char(std::string literal)
{
    if(literal.size() == 1  && isascii(literal[0]) && !(std::isdigit(literal[0])))
    {
        return (true);
    }
    return (false);
}

bool is_double(std::string literal)
{
    int i = 0;
    if(literal[0] == '-')
    {
        i++;
    }
    if(strchr(literal.c_str(), '.') == NULL)
    {
        return false;
    }

    else
    {
        if(!isdigit(literal[i]))
           return false;
        while(literal[i])
        {
            if(isdigit(literal[i]) || (literal[i] == '.'  && literal[i + 1] && isdigit(literal[i + 1])))
             i++;
            else
                return (false);
        }
    }
    return (true);
}

bool is_float(std::string literal)
{
    int i = 0;
    if(literal[0] == '-')
    {
        i++;
    }
    if(strchr(literal.c_str(), '.') == NULL)
    {
        return false;
    }
    else
    {
        if(!isdigit(literal[i]))
            return false;
        while(literal[i])
        {
            if(isdigit(literal[i]) || (literal[i] == '.'  && literal[i + 1] && isdigit(literal[i + 1])))
                i++;
            else if(literal[i + 1] == '\0' && literal[i] == 'f')
                return(true);
            else
                return false;
        }
    return (false);
    }
}

bool checkIntLimits(double number)
{
    if(!((long)number > std::numeric_limits<int>::min() && (long)number < std::numeric_limits<int>::max()))
    {
        return false;
    }
    return true;
}

bool isDisplayable(double number)
{
    if (!(number >= 32 && number <= 126)) {
        return (false);
    }
    return (true);
}

void castIntToAnotherType(double value)
{
    int castInt;
    char  castChar;
    float castFloat;
    double castDouble;
    
    castInt = static_cast<int>(value);
    castDouble = static_cast<double>(castInt);
    castChar = static_cast<char>(castInt);
    castFloat = static_cast<float>(castInt);
    std::cout << "char: ";
    if(isDisplayable(value))
    {
         std::cout << "'" << castChar << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if(checkIntLimits(value))
    {
        std::cout << castInt << std::endl;
    }
    else 
    {
        std::cout << "impossible" << std::endl;
    }    
    std::cout << "float: " << castFloat << ".0f" << std::endl;
    std::cout << "double: " << castDouble << ".0" << std::endl;
}

void castCharToAnotherType(std::string value)
{
    int castInt;
    char  castChar;
    float castFloat;
    double castDouble;
    //checkCharLimits(value); //TODO does char have limits ?
       
    castChar = static_cast<char>(value[0]);
    castInt = static_cast<int>(castChar);
    castDouble = static_cast<double>(castChar);
    castFloat = static_cast<float>(castChar);
    std::cout << "char: ";
    if(isDisplayable(castChar))
    {
         std::cout << "'" << castChar << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: " << castInt << std::endl;
    std::cout << "float: " << castFloat << ".0f" << std::endl;
    std::cout << "double: " << castDouble << ".0" << std::endl;
}

void castFloatToAnotherType(double value)
{
    int castInt;
    char  castChar;
    float castFloat;
    double castDouble;

    castFloat = static_cast<float>(value);
    castInt = static_cast<int>(castFloat);
    double decimalPart = value - castInt;
    castDouble = static_cast<double>(castFloat);
    castChar = static_cast<char>(castFloat);
    std::cout << "char: ";
    if(isDisplayable(value))
    {
         std::cout << "'" << castChar << "'" << std::endl;
    } 
    else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: " << castInt << std::endl;
    std::cout << "float: ";
    if (decimalPart != 0.0) 
    {
        std::cout << castFloat << "f" << std::endl;
    } 
    else
    {
        std::cout << castFloat << ".0f" << std::endl;
    }
    std::cout << "double: ";
    if (decimalPart != 0.0)
    {
        std::cout << castDouble << std::endl;
    } 
    else
    {
        std::cout<< castDouble << ".0" << std::endl;
    }
}

void castImpossibleToAnotherType(double value)
{
    float castFloat;
    double castDouble;

    castFloat = static_cast<float>(value);
    castDouble = static_cast<double>(value);
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << castFloat << "f" <<std::endl;
    std::cout << "double: " << castDouble << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    //TODO not working 
    const char *line = str.c_str();
    double tmp = std::strtod(line, NULL);

    if(tmp == INFINITY || tmp == -INFINITY || tmp != tmp)
    {
        castImpossibleToAnotherType(tmp);
    }
    else if(is_int(str))
    {
        castIntToAnotherType(tmp);
    }
    else if(is_char(str))
    {
        castCharToAnotherType(str);
    }
    else if(is_float(str))
    {
        castFloatToAnotherType(tmp);
    }
    else if(is_double(str) == true)
    {
        castFloatToAnotherType(tmp);
    }
    else
    {
        std::cout << "Passed Parameter isn't convertable" << std::endl;
    }
}
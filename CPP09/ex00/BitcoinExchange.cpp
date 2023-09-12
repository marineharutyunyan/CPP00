#include"BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

std::string& ltrim(std::string &str, std::string const &whitespace = " \r\n\t\v\f")
{
    str.erase(0, str.find_first_not_of(whitespace));
    return str;
}

std::string& rtrim(std::string &str, std::string const &whitespace = " \r\n\t\v\f")
{
    str.erase(str.find_last_not_of(whitespace) + 1);
    return str;
}
 
std::string& trim(std::string &str)
{
   const std::string  &whitespace=" \r\n\t\v\f";
    return ltrim(rtrim(str, whitespace), whitespace);
}

bool areAllDigits(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool IsLeap (int year) { 
 bool isLeap;   
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
              isLeap = true;
            else
               isLeap = false;
        }
        else
           isLeap = true;
    }
    else
    isLeap= false;
    return isLeap;
}

int getYear(const std::string &key)
{   
    size_t yerarseparatorIndex = key.find("-");
    std::string year;
    if (yerarseparatorIndex == std::string::npos)
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    year = key.substr(0, yerarseparatorIndex);
    if(!areAllDigits(year))
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    return std::atoi(year.c_str());
}

int getMonth(const std::string &key)
{   
    size_t yerarseparatorIndex = key.find("-");
    size_t monthSeparatorIndex = key.find("-", yerarseparatorIndex + 1);

    if (monthSeparatorIndex == std::string::npos)
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    std::string month;
    month = key.substr(yerarseparatorIndex + 1, monthSeparatorIndex - yerarseparatorIndex - 1);
    if (monthSeparatorIndex == key.length() - 1)
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    if(!areAllDigits(month))
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    return std::atoi(month.c_str());
}

int getDay(const std::string &key)
{   
    size_t yerarseparatorIndex = key.find("-");
    size_t monthSeparatorIndex = key.find("-", yerarseparatorIndex + 1);
    std::string day = key.substr(monthSeparatorIndex + 1);
    if(!areAllDigits(day))
    {
        throw std::logic_error(std::string("Error: bad input => ") + key);
    }
    return std::atoi(day.c_str());
}

bool isValidKey(const std::string &key)
{
    try
    {
        if (isDateValid(getMonth(key), getDay(key), getYear(key)) == false) {
            return false;
        } 
        return (true);   
    }
    catch(const std::exception& e)
    {
        return false;
    }    
}

bool isDateValid(int month, int day, int year) {
    bool validation = true;
    if (day < 1)
        validation = false;
    switch (month) {
        case 2:
            if (IsLeap(year)){
                if (day > 29)
                    validation = false;
            } else if (day > 28) {
                validation = false;
            }
            break;
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8: 
        case 10:
        case 12:
            if (day > 31)
            validation = false;
            break;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            if (day > 30)
            validation = false;
            break;
        default:
            validation = false;
            break;
    }
    return validation;
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &dataFile) {
    std::ifstream file(dataFile);
    std::string line;

    if (!file.is_open()) {
        throw std::logic_error("Error: could not open file.");
    }

    while (std::getline(file, line, ',')) {
        std::string key = line;
        std::getline(file, line);
        key = trim(key);
        line = trim(line);
        _map[key] = line;
    }

    file.close();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	_map = obj._map;
};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this != &obj) {
		_map = obj._map;
	}
	return (*this);
};

void BitcoinExchange::exchange(const std::string &inputFile)
{
    std::ifstream file(inputFile);

    if (!file.is_open()) {
        throw std::logic_error("Error: could not open file.");
    }
    
    std::string line;
    std::string key;
    std::string value;
    while (std::getline(file, line)) {
        size_t seperatorIndex = line.find("|");
        if (seperatorIndex == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        key = line.substr(0, seperatorIndex);
        key = trim(key);
        if(!isValidKey(key)) {
            std::cerr << "Error: bad input => " << key << std::endl;
            continue ;
        }
        value = line.substr(seperatorIndex + 1);
        value = trim(value);
        std::map<std::string, std::string>::iterator it;
        it = _map.lower_bound(key);
        if ( it == _map.end()) {
            std::cerr << "Element not found" << std::endl;
        }
        else {
            try
            {
                double rate =  stod(it->second);
                double quantity =  stod(value);
                if (quantity <= 0)
                {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (quantity >= 1000)
                {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
                std::cout << key << " => " << value << " = " << (rate * quantity) << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "Error: bad input" << std::endl;
            }
        }
    }
 
    file.close();
}
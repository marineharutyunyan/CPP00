#include"BitcoinExchange.hpp"
#include <fstream>

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


void printMap(std::map<std::string, std::string>& _map)
{
    std::map<std::string, std::string>::iterator it = _map.begin();
    while (it != _map.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &dataFile) {
    std::ifstream file(dataFile);
    std::string line;

    if (!file.is_open()) {
        throw std::logic_error("Failed to open the file.");
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
        throw std::logic_error("Failed to open the file.");
    }
    
    std::string line;
    std::string key;
    while (std::getline(file, line, '|')) {
        key = line;
        line = trim(line);
        std::getline(file, line);
        key = trim(key);
        std::map<std::string, std::string>::iterator it = _map.find(key);  
        if ( it == _map.end()) {  
            std::cout<<"Element not found" << std::endl;  
        }   
        else {
            std::cout <<  "line = " << key << std::endl;  
            std::cout << "Iterator points to " << it->first << " = " << it->second << std::endl;  
        }  
    }
 
    file.close();
}




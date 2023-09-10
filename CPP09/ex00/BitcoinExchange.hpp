#ifndef  BITCOIN_EXCHANGE_HPP
# define  BITCOIN_EXCHANGE_HPP
# include<iostream>
# include<map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &dataFile);
        BitcoinExchange(const BitcoinExchange &obj);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        void exchange(const std::string &inputFile);
    private:
        std::map<std::string, std::string> _map;
};

#endif
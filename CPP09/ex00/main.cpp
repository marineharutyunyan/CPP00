#include"BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    try
    {
        if(argc == 2)
        {
            BitcoinExchange obj("data.csv");
            obj.exchange(argv[1]);
        }
        else
        {
            std::cout << "Error: could not open file." << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
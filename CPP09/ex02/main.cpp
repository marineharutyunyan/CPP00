#include"PmergeMe.hpp"

int main (int argc, char **argv)
{
    try
    {
        if(argc >= 2)
        {
            std::vector<int> data;
            data.reserve(argc);
            // obj.fillContainer(1000);
            for (int i = 1; i <= argc-1; i++)
            {
                if (legal_int(argv[i]))
                    data.push_back(std::atoi(argv[i]));
                else 
                    throw std::logic_error("Invaled numbers sequance");
            }
            PmergeMe obj(data.begin(), data.end());
            obj.sort();
        }
        else 
        {
            std::cerr << "Error" << std::endl; 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
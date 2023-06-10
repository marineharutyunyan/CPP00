#include "iostream"
#include <fstream>

void replace(std::string fileName, std::string line)
{
    std::ofstream   repFile(fileName, std::ios::app);
    if (!repFile)
    {
        std::cout << "Error creating the file." << std::endl;
    }
    else 
    {
        repFile << line;
        repFile.close();
    }
}

int main (int argc, char **argv)
{
    if (argc == 4)
    {

        std::ifstream file(argv[1]);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else
        {
            std::cout << "Failed to open the file" << std::endl;
        }
    }
    return 0;
}
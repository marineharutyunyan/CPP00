#include "iostream"
#include <fstream>

std::string findAndReplace(std::string line, const std::string s1, const std::string s2) {
    std::string newLine;
    size_t lineLen = line.length();
    size_t s1Len = s1.length();

    size_t start = 0;
    size_t found = line.find(s1);

    while (found < lineLen) {
        newLine += line.substr(start, found - start);
        newLine += s2;
        start = found + s1Len;
        found = line.find(s1, start);
    }
    newLine += line.substr(start);

    return newLine;
}

int main (int argc, char **argv)
{
    if (argc == 4)
    {
        std::string outputName = std::string(argv[1]) + ".replace";
        std::ifstream inputFile(argv[1]);
        std::ofstream outputFile(outputName);

        if (!inputFile || !outputFile) 
        {
            std::cerr << "Failed to open files." << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(inputFile, line)) 
        {
            outputFile <<  findAndReplace(line,argv[2], argv[3]) << std::endl;
        }
        inputFile.close();
        outputFile.close();
    }
    else
    {
        std::cout << "Wrong argumet number" << std::endl;
    }

    return 0;
}
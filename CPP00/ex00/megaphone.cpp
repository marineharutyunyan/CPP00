#include <iostream>

int		main(int argc, char **argv) {
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else 
    {
        int i; 
        int j;

        i = 1;
        
        while (argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                std::cout << (char) std::toupper(argv[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl; 
    }
    return 0;
}
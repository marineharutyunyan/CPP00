#include "Serializer.hpp"

int main ()
{
    Data dataobj;
    if (&dataobj == Serializer::deserialize(Serializer::serialize(&dataobj)))
    {
        std::cout << "true" << std::endl;
    }
    else    
    {
        std::cout << "false" << std::endl;
    }
    return 0;
}
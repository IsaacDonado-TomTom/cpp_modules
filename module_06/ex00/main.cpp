#include <Convert.hpp>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Feed me ONE arguement!" << std::endl;
        return (-1);
    }
    
    Convert* converter = new Convert(argv[1]);
    if (converter->getType(1) == ERROR)
    {
        std::cerr << "ERROR: invalid input." << std::endl;
        delete converter;
        return (-1);
    }

    converter->setValue();
    std::cout << *converter;

    delete converter;
    return (0);
}
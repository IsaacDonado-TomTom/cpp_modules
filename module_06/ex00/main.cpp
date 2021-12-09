#include <Convert.hpp>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Feed me ONE arguement!" << std::endl;
        return (-1);
    }
    
    Convert* converter = new Convert(argv[1]);
    if (converter->error_num != 0)
    {
        std::cerr << "ERROR: invalid input." << std::endl;
        delete converter;
        return (-1);
    }

    converter->setValue();
    if (converter->error_num != 0)
    {
        delete converter;
        return (-1);
    }

    std::cout << *converter;
    delete converter;

    return (0);
}
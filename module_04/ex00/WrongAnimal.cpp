#include <WrongAnimal.hpp>

// WrongAnimal class functions.

WrongAnimal::WrongAnimal() : type("None")
{
    std::cout << "Generic WrongAnimal created." << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Generic WrongAnimal deleted." << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "Generic WrongAnimal copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    (void)rhs;
    std::cout << "WrongAnimal assignment overload called." << std::endl;
    this->type = rhs.type;
    return (*this);
}

const std::string&  WrongAnimal::get_type() const
{
    return (this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "" << std::endl;
    return ;
}
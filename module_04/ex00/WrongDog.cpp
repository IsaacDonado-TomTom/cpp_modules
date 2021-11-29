#include <WrongDog.hpp>
#include <WrongAnimal.hpp>
// WrongDog class functions.

WrongDog::WrongDog()
{
    this->type = "WrongDog";
    std::cout << "WrongDog created." << std::endl;
    return ;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog deleted." << std::endl;
    return ;
}

WrongDog::WrongDog(const WrongDog& src)
{
    std::cout << "WrongDog copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs)
{
    (void)rhs;
    std::cout << "WrongDog assignment overload called." << std::endl;
    this->type = rhs.get_type();
    return (*this);
}

const std::string&  WrongDog::get_type() const
{
    return (this->type);
}

void    WrongDog::makeSound() const
{
    std::cout << "WrongDog: Barf Barf... WrrrrrBARF!" << std::endl;
    return ;
}
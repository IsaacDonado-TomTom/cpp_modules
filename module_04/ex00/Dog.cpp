#include <Dog.hpp>

// Dog class functions.

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog created." << std::endl;
    return ;
}

Dog::~Dog()
{
    std::cout << "Dog deleted." << std::endl;
    return ;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

Dog& Dog::operator=(const Dog& rhs)
{
    (void)rhs;
    std::cout << "Dog assignment overload called." << std::endl;
    this->type = rhs.get_type();
    return (*this);
}

const std::string&  Dog::get_type() const
{
    return (this->type);
}

void    Dog::makeSound() const
{
    std::cout << "Dog: Barf Barf... WrrrrrBARF!" << std::endl;
    return ;
}
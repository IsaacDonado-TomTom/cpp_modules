#include <Animal.hpp>

// Animal class functions.

Animal::Animal() : type("None")
{
    std::cout << "Generic Animal created." << std::endl;
    return ;
}

Animal::~Animal()
{
    std::cout << "Generic Animal deleted." << std::endl;
    return ;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Generic animal copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

Animal& Animal::operator=(const Animal& rhs)
{
    (void)rhs;
    std::cout << "Animal assignment overload called." << std::endl;
    this->type = rhs.type;
    return (*this);
}

const std::string&  Animal::get_type() const
{
    return (this->type);
}

void    Animal::makeSound() const
{
    std::cout << "" << std::endl;
    return ;
}
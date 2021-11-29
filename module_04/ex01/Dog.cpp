#include <Dog.hpp>
// Dog class functions.

Dog::Dog()
{
    Brain*  dogBrain = new Brain;
    this->type = "Dog";
    this->dogBrain = dogBrain;
    std::cout << "Dog created." << std::endl;
    return ;
}

Dog::~Dog()
{
    delete this->dogBrain;
    std::cout << "Dog deleted." << std::endl;
    return ;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->type = src.get_type();
    this->dogBrain = new Brain(*src.get_brain());
    return ;
}

Dog& Dog::operator=(const Dog& rhs)
{
    (void)rhs;
    std::cout << "Dog assignment overload called." << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.get_type();
        this->dogBrain = rhs.get_brain();
    }
    return (*this);
}

const std::string&  Dog::get_type() const
{
    return (this->type);
}

Brain*    Dog::get_brain() const
{
    return (this->dogBrain);
}

void    Dog::makeSound() const
{
    std::cout << "Dog: Barf Barf... WrrrrrBARF!" << std::endl;
    return ;
}
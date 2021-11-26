#include <Classes.hpp>

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

// Cat class functions.

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat created." << std::endl;
    return ;
}

Cat::~Cat()
{
    std::cout << "Cat deleted." << std::endl;
    return ;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

Cat& Cat::operator=(const Cat& rhs)
{
    (void)rhs;
    std::cout << "Cat assignment overload called." << std::endl;
    this->type = rhs.get_type();
    return (*this);
}

const std::string&  Cat::get_type() const
{
    return (this->type);
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meeeeeowwww... rrrrrmeeeowww!" << std::endl;
    return ;
}
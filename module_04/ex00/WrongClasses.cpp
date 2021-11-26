#include <WrongClasses.hpp>

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

// WrongCat class functions.

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat created." << std::endl;
    return ;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat deleted." << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat& src)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    (void)rhs;
    std::cout << "WrongCat assignment overload called." << std::endl;
    this->type = rhs.get_type();
    return (*this);
}

const std::string&  WrongCat::get_type() const
{
    return (this->type);
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat: Meeeeeowwww... rrrrrmeeeowww!" << std::endl;
    return ;
}
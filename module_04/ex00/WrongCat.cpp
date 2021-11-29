#include <WrongCat.hpp>
#include <WrongAnimal.hpp>
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
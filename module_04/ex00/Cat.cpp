#include <Cat.hpp>

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
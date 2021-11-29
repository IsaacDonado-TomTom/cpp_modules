#include <Cat.hpp>
// Cat class functions.

Cat::Cat()
{
    Brain*  catBrain = new Brain;
    this->catBrain = catBrain;
    this->type = "Cat";
    std::cout << "Cat created." << std::endl;
    return ;
}

Cat::~Cat()
{
    delete this->catBrain;
    std::cout << "Cat deleted." << std::endl;
    return ;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->catBrain = new Brain(*src.get_brain());
    this->type = src.get_type();
    return ;
}

Cat& Cat::operator=(const Cat& rhs)
{
    (void)rhs;
    std::cout << "Cat assignment overload called." << std::endl;
    if (this != &rhs)
    {
        this->catBrain = rhs.get_brain();
        this->type = rhs.get_type();
    }
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

Brain*    Cat::get_brain() const
{
    return (this->catBrain);
}
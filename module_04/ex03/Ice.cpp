#include <Ice.hpp>

Ice::Ice() : AMateria("ice")
{
    //std::cout << "Ice(type) called." << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
    //std::cout << "Ice(Ice& src) called." << std::endl;
}

Ice&    Ice::operator=(const Ice& rhs)
{
    //std::cout << "Ice operator(=) called." << std::endl;
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

Ice::~Ice()
{
    //std::cout << "~Ice() called." << std::endl;
}

AMateria*   Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    AMateria::use(target);
}
#include <Cure.hpp>

Cure::Cure() : AMateria("cure")
{
    //std::cout << "Cure(type) called." << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
    //std::cout << "Cure(Cure& src) called." << std::endl;
}

Cure&    Cure::operator=(const Cure& rhs)
{
    //std::cout << "Cure operator(=) called." << std::endl;
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

Cure::~Cure()
{
    //std::cout << "~Cure() called." << std::endl;
}

AMateria*   Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    AMateria::use(target);
}
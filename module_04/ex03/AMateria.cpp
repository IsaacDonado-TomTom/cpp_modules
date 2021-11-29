#include <AMateria.hpp>
#include <ICharacter.hpp>

const std::string&  AMateria::getType() const
{
    return (this->_type);
}

AMateria::AMateria(const std::string& type)
{
    //std::cout << "AMateria(type) called." << std::endl;
    if ( !(type.compare("ice")) || !(type.compare("cure")) )
        this->_type = type;
}

AMateria::AMateria(const AMateria& src)
{
    //std::cout << "AMateria(AMateria& src) called." << std::endl;
    this->_type = src.getType();
}

AMateria::~AMateria()
{
    //std::cout << "~AMateria() called." << std::endl;
}

AMateria&   AMateria::operator=(const AMateria& rhs)
{
    //std::cout << "AMateria operator(=) called." << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs.getType();
    }
    return (*this);
}

void    AMateria::use(ICharacter& target)
{
    if (this->_type.compare("ice") == 0)
        std::cout << " launches ice powers at " << target.getName() << "! *" << std::endl;
    else if (this->_type.compare("cure") == 0)
        std::cout << " heals " << target.getName() << "'s HP. *" << std::endl;
}

std::ostream&   operator<<(std::ostream& output, AMateria& materia)
{
    output << "Type: [" <<materia.getType() << "]";
    return (output);
}
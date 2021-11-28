#include <Classes.hpp>

/////////////////////////////////////////////////////////////////////////
//                      AMateria | Ice | Cure                          //
/////////////////////////////////////////////////////////////////////////
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

///////////
//  Ice  //
///////////
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
////////////
//  Cure  //
////////////
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

///////////////////////////////////////////
//             Character                 //
///////////////////////////////////////////
Character::Character(){}

Character::Character(const std::string& name) : _name(name)
{
    //std::cout << "Character(" << name << ") called." << std::endl;
    int i;
    for (i = 0 ; i < 4 ; ++i)
        this->_inventory[i] = NULL;
}

Character::~Character()
{
    //std::cout << "~Character() called." << std::endl;
    int i;
    for (i = 0 ; i < 4 ; ++i)
    {
        if (this->_inventory[i] != NULL)
            delete this->_inventory[i];
    }
}

Character::Character(const Character& src)
{
    //std::cout << "Character(Character& " << src.getName() << ") called." << std::endl;
    this->_name = src.getName();
    int i;
    for (i = 0 ; i < 4 ; ++i)
    {
        if (src._inventory[i] != NULL)
            this->_inventory[i] = src._inventory[i]->clone();
    }
}

Character&  Character::operator=(const Character& rhs)
{
    //std::cout << "Character(op=)(Character& " << rhs.getName() << ") called." << std::endl;
    if (this != &rhs)
    {
        int i;
        for (i = 0; i < 4; ++i)
            delete this->_inventory[i];
        for (i = 0; i < 4; ++i)
        {
            if (rhs._inventory[i] != NULL)
                this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return (*this);
}

const std::string&  Character::getName() const
{
    return (this->_name);
}

void    Character::equip(AMateria* m)
{
    //std::cout << "Character::equip(m) called." << std::endl;
    int i;
    for (i = 0 ; i < 4 ; ++i)
    {
        if (this->_inventory[i] == m)
            return ;
    }
    for (i = 0 ; i < 4 ; ++i)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            return ;
        }
    }
    return ;
}

void    Character::unequip(int idx)
{
    //std::cout << "Character::unequip() called." << std::endl;
    if (idx < 0 || idx > 3)
        return ;
    this->_inventory[idx] = NULL;
    return ;
}

void    Character::use(int idx, ICharacter& target)
{
    //std::cout << "Character::use() called." << std::endl;
    if (idx < 0 || idx > 3)
        return ;
    if (this->_inventory[idx] == NULL)
        return;
    if (this != &target)
    {
        std::cout << "* " << this->_name;
        this->_inventory[idx]->use(target);
    }
}

void    Character::list_materias() const
{
    std::cout << "Character(" << this->_name << ")::list_materias() called." << std::endl;
    int i;
    for (i = 0 ; i < 4 ; ++i)
    {
        if (this->_inventory[i] != NULL)
            std::cout << i << ": " << *this->_inventory[i] << std::endl;
    }
}

///////////////////////////////////////////////////////////////////
//                          MateriaSource                        //
///////////////////////////////////////////////////////////////////
MateriaSource::MateriaSource()
{
    int i;
    for (i = 0;i<4;++i)
        this->_materia[i] = NULL;
    //std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::~MateriaSource()
{
    int i;
    for (i = 0;i<4;++i)
    {
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
    }
    //std::cout << "MateriaSource deleted." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    //std::cout << "MateriaSource cloned." << std::endl;
    int i;
    for (i = 0;i<4;++i)
    {
        if (src._materia[i] != NULL)
            this->_materia[i] = src._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs)
{
    //std::cout << "MateriaSource assigned." << std::endl;
    if (this != &rhs)
    {
        int i;
        for (i = 0; i < 4; ++i)
            delete this->_materia[i];
        for (i = 0; i < 4; ++i)
        {
            if (rhs._materia[i] != NULL)
                this->_materia[i] = rhs._materia[i]->clone();
            else
                this->_materia[i] = NULL;
        }
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* materia)
{
    if (materia != NULL)
    {
        int i;
        for (i = 0;i < 4;++i)
        {
            if (this->_materia[i] == NULL)
            {
                this->_materia[i] = materia->clone();
                return ;
            }
        }
    }
}

AMateria*   MateriaSource::createMateria(const std::string& type)
{
    int i;
    for (i = 0;i<4;++i)
    {
        if (this->_materia[i] != NULL)
        {
            if ((this->_materia[i]->getType()).compare(type) == 0)
                return (this->_materia[i]->clone());
        }
    }
    return NULL;
}

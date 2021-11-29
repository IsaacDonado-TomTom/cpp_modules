#include <Character.hpp>

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
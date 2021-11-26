#include "ClapTrap.hpp"

ClapTrap    &ClapTrap::operator=(ClapTrap const & other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "ClapTrap " << this->name << " cloned using the asignment operator." << std::endl;
    std::cout << "\033[35mClapTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    *this = other;
    std::cout << "\033[35mClapTrap " << this->name << " has been copied through the consructor overload.\033[39m" << std::endl;
    std::cout << "\033[35mClapTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "\033[35mClapTrap created, the name is " << this->name << "\033[39m" << std::endl;
    std::cout << "\033[35mClapTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[35mClapTrap " << this->name << " has been destroyed.\033[39m" << std::endl;
    return ;
}

void    ClapTrap::attack(std::string const &target) const
{
    if (this->hit_points > 0)
        std::cout << this->name << " has attacked " << target << " and caused " << this->attack_damage << " points in damage." << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->hit_points)
    {
        std::cout << this->name << " received an attack and died." << std::endl;
        this->hit_points = 0;
    }
    else
    {
        this->hit_points = this->hit_points - amount;
        std::cout << this->name << " received " << amount << " damage points, his/her HP is now " << this->hit_points << "." << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        this->hit_points = this->hit_points + amount;
        std::cout << this->name <<  " has been repaired with " << amount << " HP points. The HP has been restored to " << this->hit_points << "."  << std::endl;
    }
}
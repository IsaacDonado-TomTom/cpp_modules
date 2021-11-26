#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[36mScavTrap " << this->name << " has been created.\033[39m" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "\033[36mScavTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
    std::cout << "\033[36mScavTrap " << this->name << " has been copied through the consructor overload.\033[39m" << std::endl;
    std::cout << "\033[36mScavTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[36mScavTrap " << this->name << " has been desroyed.\033[39m" << std::endl;
    return ;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const & other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "\033[36mScavTrap " << this->name << " cloned using the asignment operator.\033[39m" << std::endl;
    std::cout << "\033[36mScavTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return (*this);
}

void    ScavTrap::guardGate()
{
    if (this->hit_points > 0)
        std::cout << "ScavTrap " << this->name << " is now in gate-keeping mode." << std::endl;
    return ;
}

void    ScavTrap::attack(std::string const &target) const
{
    if (this->hit_points > 0)
        std::cout << this->name << " has attacked " << target << " with a chainsaw and caused " << this->attack_damage << " points in damage." << std::endl;
    return ;
}
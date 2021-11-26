#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
    std::cout << "\033[33mFragTrap " << this->name << " has been copied through the consructor overload.\033[39m" << std::endl;
    std::cout << "\033[33mFragTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[33mFragTrap " << this->name << " has been created.\033[39m" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "\033[33mFragTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[33mFragTrap " << this->name << " has been desroyed.\033[39m" << std::endl;
    return ;
}

FragTrap    &FragTrap::operator=(FragTrap const & other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "\033[33mFragTrap " << this->name << " cloned using the asignment operator.\033[39m" << std::endl;
    std::cout << "\033[33mFragTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return (*this);
}

void    FragTrap::highFiveGuys()
{
    if (this->hit_points > 0)
        std::cout << "FragTrap " << this->name << " kindly requests a high fives. Beep Boop." << std::endl;
    return ;
}

void    FragTrap::attack(std::string const &target) const
{
    if (this->hit_points > 0)
        std::cout << this->name << " has attacked " << target << " with a flamethrower and caused " << this->attack_damage << " points in damage." << std::endl;
}
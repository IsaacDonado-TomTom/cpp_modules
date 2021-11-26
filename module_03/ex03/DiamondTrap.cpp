#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other.ClapTrap::name), ScavTrap(other.name), FragTrap(other.name)
{
    this->name = other.name;
    std::cout << "\033[32mDiamondTrap " << this->name << " has been copied through the consructor overload.\033[39m" << std::endl;
    std::cout << "\033[32mDiamondTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
    std::cout << "\033[32mDiamondTrap " << this->name << " has been created.\033[39m" << std::endl;
    std::cout << "\033[32mDiamondTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;

    return ;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[32mDiamondTrap " << this->name << " has been desroyed.\033[39m" << std::endl;
    return ;
}

DiamondTrap    &DiamondTrap::operator=(DiamondTrap const & other)
{
    this->name = other.name;
    ClapTrap::name = other.ClapTrap::name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "\033[32mDiamondTrap " << this->name << " cloned using the asignment operator.\033[39m" << std::endl;
    std::cout << "\033[32mDiamondTrap " << this->name << " has " << this->hit_points << " hit points, " << this->energy_points << " energy points, " <<  " and " << this->attack_damage << " attack damage.\033[39m" << std::endl;
    return (*this);
}

void    DiamondTrap::attack(std::string const &target) const
{
    ScavTrap::attack(target);
    return ;
}

void    DiamondTrap::whoAmI() const
{
    std::cout << "\033[32mDiamondTrap(" << this->name << "): Greetings. My diamond-name is " << this->name << " but my heritage name is "<< this->ClapTrap::name << "." << std::endl;
    return ;
}
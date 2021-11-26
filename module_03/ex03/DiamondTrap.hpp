#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
    DiamondTrap    &operator=(DiamondTrap const &other);
    void    attack(std::string const &target) const;
    void    whoAmI() const;
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &other);
    ~DiamondTrap();
    private:
    std::string name;
    DiamondTrap();
};

#endif
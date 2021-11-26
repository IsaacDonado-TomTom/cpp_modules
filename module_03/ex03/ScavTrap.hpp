#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
    void    guardGate();
    void    attack(std::string const &target) const;
    ScavTrap    &operator=(ScavTrap const &other);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &other);
    ~ScavTrap();
    private:
    ScavTrap();
};

#endif
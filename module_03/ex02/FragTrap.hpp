#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    void    highFiveGuys();
    void    attack(std::string const &target) const;
    FragTrap    &operator=(FragTrap const &other);
    FragTrap(std::string name);
    FragTrap(FragTrap const &other);
    ~FragTrap();
    private:
    FragTrap();
};

#endif
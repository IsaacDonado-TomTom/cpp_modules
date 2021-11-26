#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap{
    private:
    ClapTrap();

    protected:
    std::string name;
    unsigned int hit_points;
    unsigned int energy_points;
    unsigned int attack_damage;

    public:
    ClapTrap(std::string name);
    void    attack(std::string const &target) const;
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    ClapTrap    &operator=(ClapTrap const &other);
    ClapTrap(ClapTrap const &original);
    ~ClapTrap();
};

#endif
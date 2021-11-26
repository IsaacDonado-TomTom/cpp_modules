#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    {
        ClapTrap first("Brandon");
        first.attack("Sussy");
        first.takeDamage(4);
        first.beRepaired(10);
        first.takeDamage(20);
        first.attack("Robbie");
    }

    {
    ScavTrap second("Rossy");
    second.beRepaired(50);
    second.takeDamage(140);
    second.attack("Bill");
    second.guardGate();
    second.takeDamage(15);
    second.guardGate();

        {
        ScavTrap third("Fred");
        third = second;
        ScavTrap fourth(third);
        }
    }
    return (0);

}
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    {
        FragTrap fifth("George");
        fifth.highFiveGuys();
        fifth.takeDamage(5);
        fifth.attack("Bobbie");
        FragTrap sixth("Bob");
        sixth = fifth;
    }

    DiamondTrap seventh("Luigi");
    seventh.attack("Mario");
    DiamondTrap eigth("Princess");
    eigth = seventh;
    DiamondTrap nineth(eigth);
    nineth.attack("Robbie");
    nineth.guardGate();
    nineth.highFiveGuys();
    nineth.whoAmI();
    return (0);

}
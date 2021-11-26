/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 17:41:10 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/25 18:28:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack() const
{
	std::cout << this->name << " has attacked using " << this->_weapon.getType() << std::endl;
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}
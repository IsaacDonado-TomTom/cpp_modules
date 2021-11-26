/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 17:29:15 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/25 18:07:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void				Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string	Weapon::getType() const
{
	return ((const std::string)this->type);
}

Weapon::Weapon(/* args */)
{
}

Weapon::Weapon(std::string	type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}
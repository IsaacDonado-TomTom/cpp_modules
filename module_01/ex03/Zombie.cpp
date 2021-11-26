/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:14:44 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/01 20:40:05 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name, std::string type) : name(name), type(type)
{
	std::cout << type << " zombie [" << name << "] has spawned." << std::endl;
}

Zombie::~Zombie()
{
}

void	Zombie::announce(void) const
{
	std::cout << '<' << this->name << ' ' << this->type << "> Brrrraaaaaaaaiiiiiinnnnnnsssss......" << std::endl;
}
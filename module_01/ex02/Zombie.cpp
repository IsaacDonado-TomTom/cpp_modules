/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:14:44 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:40:17 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name), type(type)
{
	std::cout << type << " zombie [" << name << "] has spawned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << type << " zombie [" << name << "] has been destroyed." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << '<' << this->name << ' ' << this->type << "> Brrrraaaaaaaaiiiiiinnnnnnsssss......" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/25 23:43:14 by idonado       #+#    #+#                 */
/*   Updated: 2020/10/28 18:04:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name_init, std::string color_init, int legs_init, int horns_init) :
name(name_init), color(color_init), legs(legs_init), horns(horns_init) 
{
	std::cout << std::endl << "You've created a " << this->color <<
	" pony called [" << this->name << "] with " << this->horns <<
	" horn(s) and " << this->legs << " leg(s), nature is so beautiful!" << std::endl << std::endl;
}

Pony::~Pony()
{
	std::cout << std::endl << this->name << " has reached the slaughterhouse and will be turned into\
 ground pony beef. Not good :(" << std::endl << std::endl;
}

void	Pony::fly()
{
	std::cout << "Oh yeah, also, " << this->name << " has wings\
 and it just flew around the world, all in a few seconds." << std::endl;
}

void	Pony::jump(int meters)
{
	std::cout << std::endl << this->name << 
	" jumped " << meters << " meters in the air! WOW, ponies jump so high."
	<< std::endl << std::endl;
}

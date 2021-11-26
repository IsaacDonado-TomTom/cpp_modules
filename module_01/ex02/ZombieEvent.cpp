/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:14:44 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:37:17 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	srand((unsigned int)time(NULL));
	return;
}

std::string	ZombieEvent::randomName()
{
	std::string random_name[] = {"Kyle", "Stan", "Kenny", "Stuart",
        "George", "Edward", "Michael", "Sam", "Jack", "Charles", "Darius",
        "Donald", "Joseph", "Joshua", "Brad", "Brandon", "Jim", "Bobby",
		"Jessica", "Jennifer", "Stefan", "Gloria", "Kelsey", "Chelsea"};
        return (random_name[rand() % 23]);
}

ZombieEvent::~ZombieEvent()
{
	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name) const
{
	Zombie	*newZombie = new Zombie(name, this->type);
	return (newZombie);	
}

void	ZombieEvent::randomChump()
{
	std::string random_name;

	random_name = this->randomName();
	Zombie	newRandomChump(random_name, this->type);
	newRandomChump.announce();
}

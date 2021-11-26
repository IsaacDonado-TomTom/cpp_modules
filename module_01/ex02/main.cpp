/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:13:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:41:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent	zombie_event;
	Zombie		*zombie1;
	Zombie		*zombie2;
	Zombie		*zombie3;
	Zombie		custom_zombie("Jimmy", "Fluffy");

	zombie_event.setZombieType("Blood Sucker");
	zombie1 = zombie_event.newZombie("Jeffry Eipstein");
	zombie2 = zombie_event.newZombie("Bill Cosby");
	zombie3 = zombie_event.newZombie("Bernie Sanders");

	zombie_event.setZombieType("Brain Eater");

	zombie_event.randomChump();
	zombie_event.randomChump();
	zombie_event.randomChump();

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();
	custom_zombie.announce();

	delete zombie1;delete zombie2;delete zombie3;
	return (0);
}
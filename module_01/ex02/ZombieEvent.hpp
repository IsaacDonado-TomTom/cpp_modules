/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 00:14:55 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:35:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string	type;
	std::string	randomName(void);
public:
	void		setZombieType(std::string type);
	Zombie		*newZombie(std::string name) const;
	void		randomChump(void);
	ZombieEvent();
	~ZombieEvent();
};

#endif
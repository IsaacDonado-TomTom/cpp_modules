/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 20:27:24 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:49:31 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
private:
	std::string	randomName();
	ZombieHorde();
public:
	Zombie	*zombies;
	ZombieHorde(int N);
	~ZombieHorde();
};

#endif
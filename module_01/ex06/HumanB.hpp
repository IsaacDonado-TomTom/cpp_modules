/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 17:41:22 by idonado       #+#    #+#                 */
/*   Updated: 2020/12/08 15:43:01 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon		*_weapon;
	HumanB(/* args */);
public:
	void		setWeapon(Weapon &weapon);
	void		setName(std::string name);
	void		attack() const;
	HumanB(std::string name);
	~HumanB();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 17:41:24 by idonado       #+#    #+#                 */
/*   Updated: 2020/12/08 15:42:34 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		&_weapon;
	HumanA(/* args */);
public:
	void		attack() const;
	void		setName(std::string);
	void		setWeapon(Weapon weapon);
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
};

#endif
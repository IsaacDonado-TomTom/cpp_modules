/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 17:29:35 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/25 18:07:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	type;
public:
	void				setType(std::string type);
	const std::string	getType() const;
	Weapon(/* args */);
	Weapon(std::string type);
	~Weapon();
};

#endif
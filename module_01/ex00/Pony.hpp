/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/25 23:43:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/14 08:18:06 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
private:
	std::string	name;
	std::string color;
	int			legs;
	int			horns;
	Pony();
public:
	void		fly();
	void		jump(int meters);
	Pony(std::string name_init, std::string color_init, int legs_init, int horns_init);
	~Pony();
};
#endif
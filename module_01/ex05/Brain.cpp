/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:28:02 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/18 20:14:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(/* args */)
{
}

Brain::~Brain()
{
}

std::string	Brain::identify() const
{
	std::string 		address_str;
	const void			*address;
	std::stringstream	stringstream;

	address = this;
	stringstream << address;
	address_str = stringstream.str();
	return (address_str);
}
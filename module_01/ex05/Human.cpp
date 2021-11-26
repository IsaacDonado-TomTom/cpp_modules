/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Human.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:54:50 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/18 20:16:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(/* args */)
{
}

Human::~Human()
{
}

std::string	Human::identify() const
{
	return (this->_brain.identify());
}

const Brain	&Human::getBrain() const
{
	return (this->_brain);
}
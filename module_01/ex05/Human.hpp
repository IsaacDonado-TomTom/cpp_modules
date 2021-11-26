/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Human.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:55:34 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/18 20:16:29 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	const Brain _brain;
public:
	std::string	identify() const;
	const Brain	&getBrain() const;
	Human(/* args */);
	~Human();
};

#endif
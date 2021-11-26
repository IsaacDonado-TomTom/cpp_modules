/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:25:35 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/18 20:14:24 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	/* data */
public:
	std::string	identify() const;
	Brain(/* args */);
	~Brain();
};

#endif
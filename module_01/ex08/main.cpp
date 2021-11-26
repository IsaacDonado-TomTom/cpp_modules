/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 18:16:38 by idonado       #+#    #+#                 */
/*   Updated: 2020/12/08 16:16:14 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int	main(void)
{
	Human bobby;
	bobby.action("meleeAttack", "Fred");
	bobby.action("rangedAttack", "Fred");
	bobby.action("intimidatingShout", "Fred");
	bobby.action("Booga", "Fred");
	return (0);
	}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/25 23:42:57 by idonado       #+#    #+#                 */
/*   Updated: 2020/10/28 18:00:44 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony	*ponyOnTheHeap(std::string color, int horns, int legs)
{
	Pony	*Frank = new Pony("Frank", color, horns, legs);
	return (Frank);
}

void	ponyOnTheStack(std::string color, int horns, int legs)
{
	Pony	Jeffrey("Jeffrey", color, horns, legs);

	Jeffrey.fly();
	Jeffrey.jump(43);
}

int	main(void)
{
	Pony	*Frank;

	Frank = ponyOnTheHeap("green", 1, 3);
	ponyOnTheStack("blue", 2, 4);
	Frank->fly();
	Frank->jump(22);
	delete	Frank;
	return (0);
}

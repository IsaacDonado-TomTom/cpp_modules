/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 19:24:28 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/18 20:08:40 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human	bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
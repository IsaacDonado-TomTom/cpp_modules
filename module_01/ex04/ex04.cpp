/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex04.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 18:27:26 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/26 17:36:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str1 = "HI THIS IS BRAIN";
	std::string	*str2 = &str1;
	std::string	&str3 = str1;

	std::cout << *str2 << std::endl;
	std::cout << str3 << std::endl;
	return (0);
}
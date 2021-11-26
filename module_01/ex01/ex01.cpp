/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 00:16:10 by idonado       #+#    #+#                 */
/*   Updated: 2020/09/20 21:07:10 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	memoryLeak()
{
	std::string	*panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete panther;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Human.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 18:17:25 by idonado       #+#    #+#                 */
/*   Updated: 2020/12/01 21:10:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "You have attacked [" << target << "] with a sword!" << std::endl;
}

void	Human::rangedAttack(std::string const &target)
{
	std::cout << "You have attacked [" << target << "] with a crossbow!" << std::endl;
	
}

void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "You have shouted mean things at [" << target << "]." << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	std::string actions[3];
	typedef	void	(Human::*ActionFunctions)(std::string const &target);

	actions[0] = "meleeAttack";
	actions[1] = "rangedAttack";
	actions[2] = "intimidatingShout";

	ActionFunctions actions_function[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	int i = 0;
	while (i <= 2)
	{
		if (action_name == actions[i])
		{
			(this->*actions_function[i])(target);
			return ;
		}
		i++;
	}
	std::cout << "Invalid Action Name" << std::endl;
	return ;
}
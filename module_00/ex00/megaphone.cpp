/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 16:56:36 by idonado       #+#    #+#                 */
/*   Updated: 2021/01/20 17:28:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	int i;
	int current_arg;
	int	max_args;

	current_arg = 1;
	max_args = argc - 1;
	i = 0;

	std::string args[max_args];

	while (current_arg <= max_args)
	{
		args[i] = std::string(argv[current_arg]);
		i++;
		current_arg++;
	}

	current_arg = 0;
	while (current_arg < max_args)
	{
		std::transform(args[current_arg].begin(), args[current_arg].end(), args[current_arg].begin(), ::toupper);
		std::cout << args[current_arg];
		current_arg++;
	}
	std::cout << std::endl;
	return (0);
}
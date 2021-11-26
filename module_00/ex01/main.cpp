/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:39:07 by idonado       #+#    #+#                 */
/*   Updated: 2021/01/21 17:57:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

void	truncate_str(std::string str)
{
	size_t str_size;

	str_size = str.size();
	if (str_size == 10)
		std::cout << str;
	else if (str_size < 10)
		std::cout << std::setw(10) << std::right << std::setfill(' ') << str;
	else
		std::cout << str.substr(0, 9) << '.';
}

void	list_contacts(Contact contact[8], int current_slot)
{
	int		index;

	index = 0;
	std::cout << std::endl << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	while (index < current_slot)
	{
		std::cout << "         " << index << "|";
		truncate_str(contact[index].getInfo("firstname"));
		std::cout << "|";
		truncate_str(contact[index].getInfo("lastname"));
		std::cout << "|";
		truncate_str(contact[index].getInfo("nickname"));
		std::cout << std::endl;
		index++;
	}
	return;
}

void	search(Contact contact[8], int current_slot)
{
	std::string	command;
	int			index;
	bool		loop;

	list_contacts(contact, current_slot);
	loop = true;
	while (loop == true)
	{
		std::cout << std::endl << "Enter the index number to view more information." << std::endl;
		if (!(std::getline(std::cin, command)))
			return ;
		index = command[0] - '0';
		if (command.length() != 1 || !std::isdigit(command[0]) || command[0] > '7' || index >= current_slot)
			std::cout << "\033[31mError: Enter a valid index number.\033[39m" << std::endl;
		else
		{
			contact[index].list_info();
			loop = false;
		}
	}
	return;
}

int		main(void)
{
	Contact		contact[8];
	std::string command;
	int			current_slot;
	bool		exit;

	current_slot = 0;
	exit = false;
	while (exit == false)
	{
		std::cout << std::endl << "Enter a command. [" << Contact::slots_left << "] slots left." << std::endl << "ADD, SEARCH or EXIT (case-sensitive)" << std::endl;
		if (!(std::getline(std::cin, command)))
		{
			std::cout << "\033[31mSo... you think you're slick, or accidently pressed ^D; Exiting program to prevent infinite loop!" << std::endl;
			return (0);
		}
		if (command.compare("ADD") == 0)
		{
			if (current_slot >= 8)
				std::cout << std::endl << "\033[31mContact list is full, redirecting you to main menu.\033[39m" << std::endl;
			else
			{
				contact[current_slot].add();
				current_slot++;
			}
		}
		else if (command.compare("SEARCH") == 0)
			if (current_slot == 0)
				std::cout << std::endl << "Please add at least one contact to the contact list," << std::endl << "redirecting to main menu." << std::endl;
			else
				search(contact, current_slot);
		else if (command.compare("EXIT") == 0)
			exit = true;
	}
	std::cout << "\033[31mProgram terminated... Deleting contacts." << std::endl;
	return (0);
}
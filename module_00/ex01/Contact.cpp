/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:45:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/01/21 17:25:17 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*          Setting static variable           */
int	Contact::slots_left = 8;

/*         Constructor and Destructor         */
Contact::Contact()
{
	this->nickname = "[blank]";
	Contact::slots_left = 8;
	return;
}
Contact::~Contact()
{
	if (this->nickname.compare("[blank]") != 0)
		std::cout << std::endl << "Contact information for " << this->nickname << " has been destroyed." << std::endl;
	return;
}

/*			Accessors for search output			*/
std::string	Contact::getInfo(std::string str)
{
	if (str.compare("firstname") == 0)
		return (this->firstname);
	else if (str.compare("lastname") == 0)
		return (this->lastname);
	else if (str.compare("nickname") == 0)
		return (this->nickname);
	else
		return (str);
}

/*                          ADD CONTACT                            */
void	Contact::add()
{
	std::cout << "First Name: ";
	std::getline(std::cin, this->firstname);
	std::cout << "Last Name: ";
	std::getline(std::cin, this->lastname);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Login: ";
	std::getline(std::cin, this->login);
	std::cout << "Postal address: ";
	std::getline(std::cin, this->postal_address);
	std::cout << "Email Address: ";
	std::getline(std::cin, this->email_address);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->phone_number);
	std::cout << "Birthday Date: ";
	std::getline(std::cin, this->birthday_date);
	std::cout << "Favorite Meal: ";
	std::getline(std::cin, this->favorite_meal);
	std::cout << "Underwear Color: ";
	std::getline(std::cin, this->underwear_color);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->darkest_secret);
	std::cout << "\033[32mContact Added Successfully.\033[39m";
	Contact::slots_left = Contact::slots_left - 1;
	return;
}

/*                           LIST INFO                             */
void	Contact::list_info()
{
	std::cout << std::endl << "First name: " << this->firstname << std::endl;
	std::cout << "Last name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Login: " << this->login << std::endl;
	std::cout << "Postal Address: " << this->postal_address << std::endl;
	std::cout << "Email Address: " << this->email_address << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Birthday Date: " << this->birthday_date << std::endl;
	std::cout << "Favorite Meal: " << this->favorite_meal << std::endl;
	std::cout << "Underwear Color: " << this->underwear_color << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl << std::endl;
	std::cout << "Redirecting you back to the main menu." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/20 13:38:37 by idonado       #+#    #+#                 */
/*   Updated: 2021/01/21 17:25:12 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
private:
	std::string firstname, lastname, nickname, login,
	postal_address, email_address, phone_number,
	birthday_date, favorite_meal, underwear_color,
	darkest_secret;
public:
	std::string	getInfo(std::string str);
	static	int	slots_left;
	void	add();
	void	list_info();
	Contact();
	~Contact();
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Class_Fixed.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 15:48:43 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/21 17:35:08 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FIXED_HPP
#define CLASS_FIXED_HPP

#include <iostream>

class Fixed{
	private:
	int	_fixedPointValue;
	static const int _fractionalBits;

	public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &original);
	Fixed	&operator = (Fixed const &current);

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
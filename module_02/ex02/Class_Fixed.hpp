/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Class_Fixed.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 15:48:43 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/24 18:43:11 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FIXED_HPP
#define CLASS_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
	int	_fixedPointValue;
	static const int _fractionalBits;

	public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &original);
	Fixed(float const value);
	Fixed(int const value);

	Fixed			&operator=(Fixed const &current);
	// Comparison Operators
	bool			operator>(Fixed const &current) const;
	bool			operator<(Fixed const &current) const;
	bool			operator>=(Fixed const &current) const;
	bool			operator<=(Fixed const &current) const;
	bool			operator==(Fixed const &current) const;
	bool			operator!=(Fixed const &current) const;

	// Arithmetic Operators
	Fixed			operator+(Fixed const &rhs) const;
	Fixed			operator-(Fixed const &rhs) const;
	Fixed			operator*(Fixed const &rhs) const;
	Fixed			operator/(Fixed const &rhs) const;
	// Pre/Post Increment/Decrement
	Fixed			&operator++();
	Fixed			operator++(int);
	Fixed			&operator--();
	Fixed			operator--(int);

	int				getRawBits() const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;

	//Non-member functions
	static Fixed		&min(Fixed &first, Fixed &second);
	const static Fixed	&min (Fixed const &first, Fixed const &second);
	static Fixed		&max(Fixed &first, Fixed &second);
	const static Fixed	&max (Fixed const &first, Fixed const &second);
};

std::ostream	&operator<<(std::ostream &output, Fixed const &object);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Class_Fixed.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 15:47:59 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/24 16:44:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Class_Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

// Non-member function --> (<<) operator
std::ostream	&operator<<(std::ostream &output, Fixed const &object)
{
	float result = object.toFloat();
	output << result;
	return (output);
}

//Constructors

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default Constructor Called." << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "\033[31mDestructor Called.\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << "Copy Constructor Called." << std::endl;
	this->operator=(original);
}

Fixed::Fixed(float const value)
{
	std::cout << "Float Constructor Called." << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(int const value)
{
	std::cout << "Int Constructor Called." << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

// Operator Overloads
Fixed	&Fixed::operator=(Fixed const &current)
{
	std::cout << "Assignment Operator Called." << std::endl;
	this->_fixedPointValue = current.getRawBits();
	return *this;
}

//Member functions
int	Fixed::getRawBits() const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int		Fixed::toInt(void) const
{
	int	result;

	result = (int)this->getRawBits() / (int)(1 << this->_fractionalBits);
	return (result);
}

float	Fixed::toFloat(void) const
{
	float	result;

	result = (float)this->getRawBits() / (float)(1 << this->_fractionalBits);
	return (result);
}
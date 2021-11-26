/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Class_Fixed.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 15:47:59 by idonado       #+#    #+#                 */
/*   Updated: 2021/02/24 18:45:40 by idonado       ########   odam.nl         */
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

//Constructors & Destructor

Fixed::Fixed() : _fixedPointValue(0)
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(Fixed const &original)
{
	this->operator=(original);
}

Fixed::Fixed(float const value)
{
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(int const value)
{
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

// Operator Overloads
Fixed	&Fixed::operator=(Fixed const &current)
{
	this->_fixedPointValue = current.getRawBits();
	return *this;
}

//Comparison Operators
bool	Fixed::operator>(Fixed const &current) const
{
	return (this->_fixedPointValue > current._fixedPointValue);
}

bool	Fixed::operator<(Fixed const &current) const
{
	return (this->_fixedPointValue < current._fixedPointValue);
}

bool	Fixed::operator>=(Fixed const &current) const
{
	return (this->_fixedPointValue >= current._fixedPointValue);
}

bool	Fixed::operator<=(Fixed const &current) const
{
	return (this->_fixedPointValue <= current._fixedPointValue);
}

bool	Fixed::operator==(Fixed const &current) const
{
	return (this->_fixedPointValue == current._fixedPointValue);
}

bool	Fixed::operator!=(Fixed const &current) const
{
	return (this->_fixedPointValue != current._fixedPointValue);
}

//Arithmetic Operators
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_fixedPointValue += 1;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_fixedPointValue -= 1;
	return (temp);
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

// Non-member functions
Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}
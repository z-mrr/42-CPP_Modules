/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:39 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/31 11:55:42 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;

Fixed::Fixed() : _nValue(0)
{
	cout << "Default constructor called\n";
}

Fixed::Fixed(const int d)
{
	cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	cout << "Float constructor called\n";
}

float	Fixed::toFloat() const
{
	return;
}

int	Fixed::toInt() const
{
	return;
}

Fixed::Fixed(Fixed const &src)
{
	cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	cout << "Copy assignment operator called\n";
	_nValue = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	cout << "getRawBits member function called\n";
	return _nValue;
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called\n";
	_nValue = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.getRawBits();
	return o;
}

const int	Fixed::_nBits = 8;

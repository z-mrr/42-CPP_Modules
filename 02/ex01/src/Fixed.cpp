/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:39 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/09 17:14:42 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;

//________________CONSTRUCTORS________________

Fixed::Fixed() : _nValue(0)
{
	cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	cout << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(const int i)
{
	cout << "Int constructor called\n";
	 _nValue = i * (1 << _nBits);
}

Fixed::Fixed(const float f)
{
	cout << "Float constructor called\n";
	 _nValue = static_cast<int>(roundf(f * (1 << _nBits)));
}

//________________DESTRUCTOR________________

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

//________________OPERATOR OVERLOADS________________

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	cout << "Copy assignment operator called\n";
	_nValue = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

//________________MEMBER FUNCTIONS________________

int	Fixed::getRawBits() const
{
	return _nValue;
}

void	Fixed::setRawBits(int const raw)
{
	_nValue = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(_nValue) / (1 << _nBits);
}

int		Fixed::toInt() const
{
	return _nValue / (1 << _nBits);
}

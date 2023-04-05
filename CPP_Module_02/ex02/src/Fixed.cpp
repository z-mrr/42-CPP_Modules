/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:39 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/14 19:19:14 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;

//________________CONSTRUCTORS________________

Fixed::Fixed() : _val(0)
{
	// cout << "Defaults constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	// cout << "Copys constructor called\n";
	*this = src;
}

Fixed::Fixed(const int i)
{
	// cout << "Int consstructor called\n";
	 _val = i * (1 << _bits);
}

Fixed::Fixed(const float f)
{
	// cout << "Float cosnstructor called\n";
	 _val = static_cast<int>(roundf(f * (1 << _bits)));
}

//________________DESTRUCTOR________________

Fixed::~Fixed()
{
	// cout << "Destructor called\n";
}

//________________OVERLOADS________________

bool	Fixed::operator>(Fixed const &ref) const
{
	return _val > ref._val;
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return _val < ref._val;
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return _val >= ref._val;
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return _val >= ref._val;
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return _val == ref._val;
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return _val != ref._val;
}

Fixed	Fixed::operator+(Fixed const &ref) const
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed	Fixed::operator-(Fixed const &ref) const
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed	Fixed::operator*(Fixed const &ref) const
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/(Fixed const &ref) const
{
	return Fixed(this->toFloat() / ref.toFloat());
}

Fixed	Fixed::operator++(int)	//postfix
{
	Fixed	tmp(*this);

	++_val;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--_val;
	return tmp;
}

Fixed	&Fixed::operator++()	//prefix
{
	++_val;
	return *this;
}

Fixed	&Fixed::operator--()
{
	--_val;
	return *this;
}


Fixed	&Fixed::operator=(Fixed const &ref)
{
	// cout << "Copy assignment operator caslled\n";
	_val = ref.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &ref)
{
	o << ref.toFloat();
	return o;
}

//________________MEMBER FUNCTIONS________________

int	Fixed::getRawBits() const
{
	return _val;
}

void	Fixed::setRawBits(int const raw)
{
	_val = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(_val) / (1 << _bits);
}

int		Fixed::toInt() const
{
	return _val / (1 << _bits);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a._val < b._val ? a : b;
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return a._val < b._val ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a._val > b._val ? a : b;
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return a._val > b._val ? a : b;
}

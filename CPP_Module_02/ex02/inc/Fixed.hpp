/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:42 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/14 19:20:03 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();

	bool	operator> (Fixed const &ref) const;
	bool	operator<(Fixed const &ref) const;
	bool	operator>=(Fixed const &ref) const;
	bool	operator<=(Fixed const &ref) const;
	bool	operator==(Fixed const &ref) const;
	bool	operator!=(Fixed const &ref) const;

	Fixed	operator+(Fixed const &ref) const;
	Fixed	operator-(Fixed const &ref) const;
	Fixed	operator*(Fixed const &ref) const;
	Fixed	operator/(Fixed const &ref) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	&operator++();
	Fixed	&operator--();

	Fixed	&operator=(Fixed const &ref);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);

private:
	int					_val;
	static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &ref);

#endif

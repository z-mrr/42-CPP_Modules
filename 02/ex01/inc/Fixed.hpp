/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:42 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/31 11:54:47 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int d);
	Fixed(const float f);
	Fixed(Fixed const &src);
	~Fixed();
	float	toFloat() const;
	int		toInt() const;
	int		getRawBits() const;
	void	setRawBits(int const raw);
	Fixed	&operator=(Fixed const &rhs);

private:
	int					_nValue;
	static const int	_nBits;
};

	std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif

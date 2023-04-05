/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:42 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/09 17:15:04 by jdias-mo         ###   ########.fr       */
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

	Fixed	&operator=(Fixed const &rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

private:
	int					_nValue;
	static const int	_nBits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif

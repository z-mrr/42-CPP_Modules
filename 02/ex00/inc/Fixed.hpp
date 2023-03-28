/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:42 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/09 16:40:10 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
	Fixed	&operator=(Fixed const &rhs);

private:
	int					_nValue;
	static const int	_nBits;
};

#endif

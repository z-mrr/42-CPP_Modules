/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:46:59 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/16 15:43:27 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(Point const &src);
	Point(float const a, float const b);
	~Point();

	Point const&	operator=(Point const& ref) const;

	Fixed	getX() const;
	Fixed	getY() const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:47:02 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/16 15:43:14 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//________________CONSTRUCTOR________________

Point::Point() : _x(0), _y(0){}

Point::Point(Point const &src) : _x(src._x), _y(src._y){}

Point::Point(float const a, float const b) : _x(a) , _y(b){}

//________________DESTRUCTOR________________

Point::~Point(){}

//________________OVERLOAD________________

Point const&	Point::operator=(Point const& ref) const
{
	std::cerr << "Cannot change const values\n";
	return	ref;
}

//________________GETTER________________

Fixed	Point::getX() const
{
	return _x;
}

Fixed	Point::getY() const
{
	return _y;
}

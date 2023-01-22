/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:15:41 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 20:47:20 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type) : _type(type)
{}

Weapon::~Weapon()
{}

std::string	const&	Weapon::getType() const
{
	return _type;
}

void		Weapon::setType(std::string newType)
{
	_type = newType;
}

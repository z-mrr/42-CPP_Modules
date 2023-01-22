/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:15:36 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 20:50:12 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << '\n';
}

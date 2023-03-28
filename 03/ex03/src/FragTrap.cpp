/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:00 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/22 21:19:30 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hp = 100;
	// _mp = 100;
	_dmg = 30;
	_maxhp = 100;
	std::cout << _name << " (FragTrap) Default constructor was called\n";
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << src._name << " (FragTrap) Copy constructor was called\n";
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_mp = 100;
	_dmg = 30;
	_maxhp = 100;
	std::cout << _name << " (FragTrap) Constructor was called and values initialized\n";
}

FragTrap::~FragTrap()
{
	std::cout << _name << " (FragTrap) Destructor was called\n";
}

FragTrap&	FragTrap::operator=(FragTrap const& ref)
{
	_name = ref._name;
	_hp = ref._hp;
	_mp = ref._mp;
	_dmg = ref._dmg;
	_maxhp = ref._maxhp;
	return *this;
}

void		FragTrap::highFivesGuys()
{
	if (_hp > 0 && _mp > 0)
		std::cout << "High Fives Guys!\n";
	else
		std::cout << "Unable to request high fives.\n";
}

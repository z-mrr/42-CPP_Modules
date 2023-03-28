/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:55:18 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/23 15:39:29 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap"), ScavTrap(), FragTrap(), _name("DiamondTrap")
{
	std::cout << _name << " (DiamondTrap) Default constructor was called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << _name << " (DiamondTrap) Constructor was called and values initialized\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << src._name << " (DiamondTrap) Copy constructor was called\n";
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << " (DiamondTrap) Destructor was called\n";
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& ref)
{
	_name = ref._name;
	_hp = ref._hp;
	_mp = ref._mp;
	_dmg = ref._dmg;
	_maxhp = ref._maxhp;
	return *this;
}

void		DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI()
{
	std::cout << "I am a DiamondTrap named " << _name << " and my ClapTrap name is " << ClapTrap::_name << "!\n";
}


void		DiamondTrap::status()
{
	std::cout << _name << "; " << _hp << " of " << _maxhp << "; " << _mp << "; " << _dmg << "\n";
}

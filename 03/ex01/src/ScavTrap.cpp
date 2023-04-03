/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:00 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/30 23:57:32 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hp = 100;
	_mp = 50;
	_dmg = 20;
	_maxhp = 100;
	std::cout << _name << " (ScavTrap) Default constructor was called\n";
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	std::cout << src._name << " (ScavTrap) Copy constructor was called\n";
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_mp = 50;
	_dmg = 20;
	_maxhp = 100;
	std::cout << _name << " (ScavTrap) Constructor was called and values initialized\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " (ScavTrap) Destructor was called\n";
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& ref)
{
	_name = ref._name;
	_hp = ref._hp;
	_mp = ref._mp;
	_dmg = ref._dmg;
	return *this;
}

void	ScavTrap::guardGate()
{
	if (_hp < 1 || _mp < 1)
		std::cout << "Gate keeper mode unavailable for " << _name << ".\n";
	else
		std::cout << _name << " is now in Gate keeper mode.\n";
}

void		ScavTrap::attack(const std::string& target)
{
	if (_hp < 1)
		return ;
	if (_mp > 0)
	{
		if (_dmg < 1)
			std::cout << "ScavTrap " << _name << " tried to attack " << target << " but has no attack damage. Still lost 1 energy for the attempt!\n";
		else
			std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!\n";
		--_mp;
	}
	else
		std::cout << "ScavTrap " << _name << " is out of energy and cannot attack " << target << "!\n";
}

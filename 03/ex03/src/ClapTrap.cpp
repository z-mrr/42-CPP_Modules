/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:53 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/22 20:51:06 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hp(10), _mp(10), _dmg(0), _maxhp(_hp)
{
	std::cout << _name << " (ClapTrap) Default constructor was called\n";
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << src._name << " (ClapTrap) Copy constructor was called\n";
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _mp(10), _dmg(0), _maxhp(_hp)
{
	std::cout << _name << " (ClapTrap) Constructor was called and values initialized\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " (ClapTrap) Destructor was called\n";
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& ref)
{
	_name = ref._name;
	_hp = ref._hp;
	_mp = ref._mp;
	_dmg = ref._dmg;
	_maxhp = ref._maxhp;
	return *this;
}

void		ClapTrap::attack(std::string const& target)
{
	if (_hp < 1)
		return ;
	if (_mp > 0)
	{
		if (_dmg < 1)
			std::cout <<  _name << " tried to attack " << target << " but has no attack damage. Still lost 1 energy for the attempt!\n";
		else
			std::cout << _name << " attacks " << target << ", causing " << _dmg << " points of damage!\n";
		--_mp;
	}
	else
		std::cout << _name << " is out of energy and cannot attack " << target << "!\n";
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp < 1)
		return ;
	std::cout << _name << " got hit for " << amount << " damage!\n";
	_hp -= amount;
	if (_hp < 1)
		std::cout << _name << " took too much damage and died!\n";
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp < 1)
		return ;
	if (_mp > 0)
	{
		--_mp;
		std::cout << _name << " is restoring health...\n";
		if (amount + _hp >= _maxhp)
		{
			std::cout << _name << " health is fully restored!\n";
			_hp = _maxhp;
		}
		else
		{
			std::cout << _name << " restored " << amount << " health!\n";
			_hp += amount;
		}
	}
	else
		std::cout << _name << " is out of energy and cannot be repaire!\n";
}

void		ClapTrap::setDmg(unsigned int ad)
{
	_dmg = ad;
}


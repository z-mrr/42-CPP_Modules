/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:47 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/21 18:48:44 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(ClapTrap const& src);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap&	operator=(ClapTrap const& ref);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	void		setDmg(unsigned int ad);

protected:
	std::string	_name;
	int			_hp;
	int			_mp;
	int			_dmg;
	unsigned int			_maxhp;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:55:21 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/30 23:44:42 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(DiamondTrap const& src);
	DiamondTrap(std::string name);
	~DiamondTrap();

	DiamondTrap&	operator=(DiamondTrap const& ref);

	void			attack(std::string const& target);
	void			whoAmI();
	void			status();

private:
	std::string		_name;
};

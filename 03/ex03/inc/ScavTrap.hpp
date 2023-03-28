/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:08 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/22 20:51:21 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const& src);
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap&	operator=(ScavTrap const& ref);

	void		guardGate();
	void		attack(std::string const& target);
};

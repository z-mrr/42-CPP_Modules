/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:08 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/21 19:01:39 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const& src);
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap&	operator=(ScavTrap const& ref);

	void		guardGate();
	void		attack(const std::string& target);
};

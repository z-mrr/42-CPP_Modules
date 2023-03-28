/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:29 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/21 19:08:33 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a;
	ScavTrap	b("Spartacus");
	ScavTrap	c(b);
	ScavTrap	d("Crixus");

	b.attack("Crixus");
	d.takeDamage(20);
	d.beRepaired(10);
	b.attack("Crixus");
	d.takeDamage(20);
	d.beRepaired(5);
	b.attack("Crixus");
	d.takeDamage(20);
	b.attack("Crixus");
	d.takeDamage(20);
	b.attack("Crixus");
	d.takeDamage(20);
	b.attack("Crixus");
	d.takeDamage(20);
	d.guardGate();
	return 0;
}


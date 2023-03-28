/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:29 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/17 17:15:01 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a;
	ClapTrap	b("Spartacus");
	ClapTrap	c(b);
	ClapTrap	d("Crixus");

	b.setDmg(9);
	c.attack("Crixus");
	b.attack("Crixus");
	d.takeDamage(9);
	d.beRepaired(10);
	b.attack("Crixus");
	d.takeDamage(9);
	d.beRepaired(5);
	b.attack("Crixus");
	d.takeDamage(9);
	d.beRepaired(5);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:29 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/21 19:47:44 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	a;
	FragTrap	b("Spartacus");
	FragTrap	c(b);
	FragTrap	d("Crixus");

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
	d.highFivesGuys();
	return 0;
}


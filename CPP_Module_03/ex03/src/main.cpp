/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:29 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/04/04 14:22:35 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	a;
	std::cout << '\n';
	DiamondTrap	b("Neiva");
	std::cout << '\n';
	DiamondTrap	c(b);
	std::cout << '\n';
	b.whoAmI();
	a.attack("Neiva");
	b.takeDamage(30);
	b.beRepaired(10);
	std::cout << '\n';
	a.status();
	b.status();
	c.status();
	c = a;
	c.status();
	std::cout << '\n';
	b.highFivesGuys();
	b.guardGate();
	return 0;
}


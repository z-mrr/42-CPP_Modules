/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:29 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/22 21:22:51 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
	return 0;
}


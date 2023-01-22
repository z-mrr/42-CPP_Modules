/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:25 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 07:58:10 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

int	main()
{
	Zombie	zombie("Matias");
	Zombie*	zombie2;

	zombie2 = newZombie("Tone");
	zombie.announce();
	zombie2->announce();
	randomChump("Arnaldo");
	delete zombie2;
	return 0;
}


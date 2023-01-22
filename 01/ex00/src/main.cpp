/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:25 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 07:25:58 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

int	main()
{
	Zombie	zombie("Matias");
	Zombie*	newZomb;

	newZomb = newZombie("Tone");
	zombie.announce();
	newZomb->announce();
	randomChump("Arnaldo");
	delete newZomb;
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:25 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/21 12:52:08 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

int	main()
{
	Zombie	zombie("Matias");
	Zombie*	newZomb = newZombombie("Tone");

	randomChump("Arnaldo");
	newZomb->announce();
	zombie.announce();
	delete newZomb;
	return 0;
}


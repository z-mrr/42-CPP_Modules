/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:25 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 10:35:35 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>
#include <iostream>

int	main()
{
	Zombie*	zombie;

	zombie = zombieHorde(3, "	");
	delete[] zombie;
	return 0;
}


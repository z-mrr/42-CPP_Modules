/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:32:05 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 09:50:21 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombie;

	if (N <= 0)
		return NULL;
	if (!name.empty())
		Zombie::defaultName = name;
	zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		// zombie[i] = Zombie(name);
		zombie[i].announce();
	}
	return zombie;
}

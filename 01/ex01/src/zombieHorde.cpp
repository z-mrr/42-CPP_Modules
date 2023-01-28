/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:32:05 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/28 18:59:19 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>
#include <string>

bool	ft_isspace(std::string s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if(!isspace(s[i]))
			return false;
	}
	return true;
}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombie;

	if (N <= 0)
		return NULL;
	zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		if (!name.empty() && !ft_isspace(name))
			zombie[i].setName(name);
		zombie[i].announce();
	}
	return zombie;
}

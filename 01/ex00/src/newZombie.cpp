/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:55:16 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/20 18:14:32 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>
#include <string>

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie	newZombie(name);

	return &newZombie;
}

void	Zombie::randomChump(std::string name)
{
	Zombie	newZombie(name);

	newZombie.announce();
}







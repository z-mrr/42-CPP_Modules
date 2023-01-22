/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:55:16 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/21 12:08:30 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <string>
#include <new>

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = new Zombie(name);

	return zombie;
}







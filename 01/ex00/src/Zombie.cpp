/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:31 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/21 12:10:59 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Spawning " << _name << '\n';
}

Zombie::~Zombie()
{
	std::cout << "Destroying " << _name << '\n';
}

void	Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::getName()
{
	return _name;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:31 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/28 18:57:30 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie() : _name("Zombie")
{}

Zombie::~Zombie()
{
	std::cout << "Destructing " << _name << '\n';
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

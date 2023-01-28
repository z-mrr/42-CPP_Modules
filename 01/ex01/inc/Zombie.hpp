/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:06 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/28 18:50:11 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void				announce();
	void				setName(std::string);

private:
	std::string	_name;
};

Zombie*					zombieHorde(int N, std::string name);

#endif

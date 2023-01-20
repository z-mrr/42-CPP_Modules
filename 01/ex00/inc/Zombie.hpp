/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:06 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/20 18:07:26 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
public:

	Zombie(std::string name);
	~Zombie();

	void		announce();
	std::string	getName();
	Zombie*		newZombie(std::string name);
	void		randomChump(std::string name);

private:

	std::string	_name;
};

#endif

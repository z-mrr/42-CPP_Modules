/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:15:00 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 20:28:28 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();
	std::string	getType() const;
	void		setType(std::string newType);

private:
	std::string			_type;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:08 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/21 19:46:07 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap const& src);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap&	operator=(FragTrap const& ref);

	void		highFivesGuys();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:58:33 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/28 19:03:32 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	Harl		h;

	if (ac != 2)
		return std::cerr << "Usage: ./harlFilter <level>\n", 1;

	std::string	level(av[1]);

	h.complain(level);
	return 0;
}

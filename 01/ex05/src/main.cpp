/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:58:33 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/27 20:51:18 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	return 0;
}

// #include <iostream>

// int	main(int ac, char **av)
// {
// 	Harl	h;

// 	if (ac != 2 || string(av[1]) != "DEBUG" || string(av[1]) != "INFO" || string(av[1]) != "WARNING" || string(av[1]) != "ERROR")
// 		return std::cout << "Usage: ./Harl <level>\nLevels: DEBUG, INFO, WARNING, ERROR\n", 1;
// 	h.complain(av[1]);
// 	return 0;
// }

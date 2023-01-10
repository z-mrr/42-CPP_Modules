/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:41:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/10 14:27:41 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <string>
#include <iostream>

int	main()
{
	Phonebook	phonebook;
	std::string	cmd;

	while (cmd != "EXIT" && !std::cin.eof() && !std::cin.fail())
	{
		clear();
		std::cout << "• ADD" << '\n';
		std::cout << "• SEARCH" << '\n';
		std::cout << "• EXIT" << '\n';
		std::cout << '\n';
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}

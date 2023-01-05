/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:41:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/04 23:48:20 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.class.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	cmd;

	while (cmd != "EXIT" && !std::cin.eof() && !std::cin.fail())
	{
		clear();
		std::cout << "• ADD" << std::endl;
		std::cout << "• SEARCH" << std::endl;
		std::cout << "• EXIT" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}

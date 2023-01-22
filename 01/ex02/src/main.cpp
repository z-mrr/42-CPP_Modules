/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:55:06 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/22 12:12:44 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int	main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::setw(20) << "string address: " << &string << '\n';
	std::cout << std::setw(20) << "stringPTR address: " << stringPTR << '\n';
	std::cout << std::setw(20) << "stringREF address: " << &stringREF << "\n\n";
	std::cout << std::setw(18) << "string value: " << string << '\n';
	std::cout << std::setw(18) << "stringPTR value: " << *stringPTR << '\n';
	std::cout << std::setw(18) << "stringREF value: " << stringREF << '\n';
	return 0;
}

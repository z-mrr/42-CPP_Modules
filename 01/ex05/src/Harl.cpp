/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:06:31 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/27 20:52:27 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

using std::cout;

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info()
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning()
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error()
{
	cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
			(this->*f[i])();
	}
}

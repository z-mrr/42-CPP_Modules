/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:06:31 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/31 17:19:06 by jdias-mo         ###   ########.fr       */
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
	cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	info();
}

void	Harl::info()
{
	cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	warning();
}

void	Harl::warning()
{
	cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	error();
}

void	Harl::error()
{
	cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i;

	for (i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*f[i])();
			break;
		case 1:
			(this->*f[i])();
			break;
		case 2:
			(this->*f[i])();
			break;
		case 3:
			(this->*f[i++])();
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

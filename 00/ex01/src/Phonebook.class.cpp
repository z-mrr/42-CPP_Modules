/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:42:55 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/05 02:09:42 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.class.hpp"

Phonebook::Phonebook(void) : _i(0), _max(0)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	clear();
	std::cout << "Exited PhoneBook. All contacts were lost" << std::endl;
	return ;
}

void	Phonebook::add(void)
{
	int	i;

	this->_i++;
	if (this->_i == 9)
		this->_i = 1;
	if (this->_max < 8)
		this->_max++;
	i = this->_i - 1;
	this->_list[i].set_fn(add_prompt("First name: "));
	this->_list[i].set_ln(add_prompt("Last name: "));
	this->_list[i].set_n(add_prompt("Nickname: "));
	this->_list[i].set_pn(add_prompt("Phone number: "));
	this->_list[i].set_ds(add_prompt("Darkest secret: "));
	clear();
	std::cout << "Contact successfully added to PhoneBook" << std::endl;
	pause();
	return ;
}

void	Phonebook::search(void) const
{
	int	i;
	int	j;
	int	max;

	std::string	str;

	clear();
	max = this->_max;
	if (!max)
	{
		std::cout << "You do not have any contacts yet" << std::endl;
		pause();
		return ;
	}
	while ((str.length() != 1 || str.c_str()[0] <= '0' || str.c_str()[0] - '0' > max))
	{
		clear();
		std::cout << "————————————————————————————————————————————" << std::endl;
		std::cout << "     INDEX|   F. NAME|   L. NAME|  NICKNAME|" << std::endl;
		std::cout << "————————————————————————————————————————————" << std::endl;
		i = -1;
		while (++i < max)
		{
			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_fn()) << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_ln()) << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_n()) << "|";
			std::cout << std::endl;
			std::cout << "————————————————————————————————————————————" << std::endl;
		}
		std::cout << std::endl << "Enter contact index (1 - ";
		std::cout << max << "): ";
		std::getline(std::cin >> std::ws, str);
		if (std::cin.eof() || std::cin.fail())
			exit (1);
	}
	j = str.c_str()[0] - '0' - 1;
	clear();
	std::cout << "Contact " << j + 1 << std::endl;
	std::cout << "————————————————————————————————————————————" << std::endl;
	std::cout << "First name:     " << this->_list[j].get_fn() << std::endl;
	std::cout << "Last name:      " << this->_list[j].get_ln() << std::endl;
	std::cout << "Nickname:       " << this->_list[j].get_n() << std::endl;
	std::cout << "Phone number:   " << this->_list[j].get_pn() << std::endl;
	std::cout << "Darkest secret: " << this->_list[j].get_ds() << std::endl;
	pause();
	return ;
}

std::string	trunc(std::string s)
{

	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s = s.append(".");
	}
	return (s);
}

std::string	add_prompt(std::string s)
{
	std::string	str;

	while (str.empty())
	{
		clear();
		std::cout << "Adding a new contact (fields can not be empty)" << std::endl;
		std::cout << std::endl;
		std::cout << s;
		std::getline(std::cin >> std::ws, str);
		if (std::cin.eof() || std::cin.fail())
			exit (1);
	}
	return (str);
}

void	pause(void)
{
	std::cout << std::endl;
	std::cout << "Press ENTER to continue" << std::endl;
	while (42)
	{
		if (std::cin.get())
			break;
	}
}

void	clear(void)
{
	system("clear");
	std::cout << "PhoneBook" << std::endl;
	std::cout << std::endl;
}

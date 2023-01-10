/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:42:55 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/10 17:39:04 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook() : _i(0), _max(0)
{
	return ;
}

Phonebook::~Phonebook()
{
	clear();
	std::cout << "Exited PhoneBook. All contacts were lost" << '\n';
	return ;
}

void	Phonebook::add()
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
	std::cout << "Contact successfully added to PhoneBook" << '\n';
	pause();
	return ;
}

void	Phonebook::search() const
{
	int			i;
	int			j;
	int			max;
	std::string	str;

	clear();
	max = this->_max;
	if (!max)
	{
		std::cout << "You do not have any contacts yet" << '\n';
		pause();
		return ;
	}
	while (str.length() != 1 || str[0] <= '0' || str[0] - '0' > max)
	{
		clear();
		std::cout << "————————————————————————————————————————————" << '\n';
		std::cout << "     INDEX|   F. NAME|   L. NAME|  NICKNAME|" << '\n';
		std::cout << "————————————————————————————————————————————" << '\n';
		i = -1;
		while (++i < max)
		{
			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_fn()) << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_ln()) << "|";
			std::cout << std::setw(10) << trunc(this->_list[i].get_n()) << "|";
			std::cout << '\n';
			std::cout << "————————————————————————————————————————————" << '\n';
		}
		std::cout << '\n' << "Enter contact index (1 - ";
		std::cout << max << "): ";
		std::getline(std::cin, str);
		if (std::cin.eof() || std::cin.fail())
			exit (1);
	}
	j = str[0] - '0' - 1;
	clear();
	std::cout << "Contact " << j + 1 << '\n';
	std::cout << "————————————————————————————————————————————" << '\n';
	std::cout << "First name:     " << this->_list[j].get_fn() << '\n';
	std::cout << "Last name:      " << this->_list[j].get_ln() << '\n';
	std::cout << "Nickname:       " << this->_list[j].get_n() << '\n';
	std::cout << "Phone number:   " << this->_list[j].get_pn() << '\n';
	std::cout << "Darkest secret: " << this->_list[j].get_ds() << '\n';
	pause();
	return ;
}

std::string	trunc(std::string s)
{
	for (int i = 0; i < static_cast<int>(s.length()); i++)//para nao desformatar a tab
	{
		if (s[i] == '\t')
			s[i] = ' ';
	}
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

	while (str.empty() || ft_isspace(str))
	{
		clear();
		std::cout << "Adding a new contact (fields can not be empty)" << '\n';
		std::cout << '\n' << s;
		std::getline(std::cin, str);
		if (std::cin.eof() || std::cin.fail())
			exit (1);
	}
	return (ft_trim_ws(str));
}

std::string	ft_trim_ws(std::string s)
{
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return(s.substr(i, s.length() - i));
}

bool	ft_isspace(std::string s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if(!std::isspace(s[i]))
			return false;
	}
	return true;
}

void	pause()
{
	std::cout << '\n';
	std::cout << "Press ENTER to continue" << '\n';
	while (42)
	{
		if (std::cin.get())
			break;
	}
}

void	clear()
{
	system("clear");
	std::cout << "PhoneBook" << '\n';
	std::cout << '\n';
}

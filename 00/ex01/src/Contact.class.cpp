/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:47:27 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/04 18:46:02 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.class.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructed" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_fn(void) const
{
	return (this->_first_name);
}

void	Contact::set_fn(std::string str)
{
	this->_first_name = str;
	return ;
}

std::string	Contact::get_ln(void) const
{
	return (this->_last_name);
}

void	Contact::set_ln(std::string str)
{
	this->_last_name = str;
	return ;
}

std::string	Contact::get_n(void) const
{
	return (this->_nickname);
}

void	Contact::set_n(std::string str)
{
	this->_nickname = str;
	return ;
}

std::string	Contact::get_pn(void) const
{
	return (this->_phone_number);
}

void	Contact::set_pn(std::string str)
{
	this->_phone_number = str;
	return ;
}

std::string	Contact::get_ds(void) const
{
	return (this->_darkest_secret);
}

void	Contact::set_ds(std::string str)
{
	this->_darkest_secret = str;
	return ;
}



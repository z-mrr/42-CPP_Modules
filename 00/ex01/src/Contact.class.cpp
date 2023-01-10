/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:47:27 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/10 12:01:09 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string	Contact::get_fn() const
{
	return (this->_first_name);
}

std::string	Contact::get_ln() const
{
	return (this->_last_name);
}

std::string	Contact::get_n() const
{
	return (this->_nickname);
}

std::string	Contact::get_pn() const
{
	return (this->_phone_number);
}

std::string	Contact::get_ds() const
{
	return (this->_darkest_secret);
}

void	Contact::set_fn(std::string str)
{
	this->_first_name = str;
	return ;
}

void	Contact::set_ln(std::string str)
{
	this->_last_name = str;
	return ;
}

void	Contact::set_n(std::string str)
{
	this->_nickname = str;
	return ;
}

void	Contact::set_pn(std::string str)
{
	this->_phone_number = str;
	return ;
}

void	Contact::set_ds(std::string str)
{
	this->_darkest_secret = str;
	return ;
}



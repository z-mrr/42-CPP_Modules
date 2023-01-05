/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:47:10 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/05 00:08:20 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Contact
{
public:

	Contact(void);
	~Contact(void);

	std::string	get_fn(void) const;
	void		set_fn(std::string);
	std::string	get_ln(void) const;
	void		set_ln(std::string);
	std::string	get_n(void) const;
	void		set_n(std::string);
	std::string	get_pn(void) const;
	void		set_pn(std::string);
	std::string	get_ds(void) const;
	void		set_ds(std::string);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:47:10 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/10 12:01:08 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{
public:

	Contact();
	~Contact();

	std::string	get_fn() const;
	std::string	get_ln() const;
	std::string	get_n() const;
	std::string	get_pn() const;
	std::string	get_ds() const;
	void		set_fn(std::string);
	void		set_ln(std::string);
	void		set_n(std::string);
	void		set_pn(std::string);
	void		set_ds(std::string);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:42:52 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/10 12:02:51 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

class Phonebook
{
public:

	Phonebook();
	~Phonebook();

	void	add();
	void	search() const;

private:

	int		_i;
	int		_max;
	Contact	_list[8];
};

std::string	trunc(std::string s);
std::string	add_prompt(std::string s);
void		pause();
void		clear();

#endif

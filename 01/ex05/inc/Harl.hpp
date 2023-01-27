/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:03:45 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/27 20:10:08 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

using std::string;

class Harl
{
public:
	Harl();
	~Harl();
	void	complain(string level);

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
};

#endif

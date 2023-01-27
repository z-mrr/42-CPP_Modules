/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:55:18 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/27 14:16:04 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::isspace;

bool	ft_isspace(string s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if(!isspace(s[i]))
			return false;
	}
	return true;
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return cerr << "Wrong number of parameters given.\n", 1;
	else if (string(av[1]).empty() || string(av[2]).empty() || string(av[3]).empty())
		return cerr << "Parameters can't me empty.\n", 1;
	else if (ft_isspace(string(av[1])))
		return cerr << "Filename can't be spaces only.", 1;

	string		s1 = av[2];
	string		s2 = av[3];
	string		f1 = av[1];
	string		f2 = string(av[1]).append(".replace");
	ifstream	ifs(f1.c_str());
	ofstream	ofs(f2.c_str());
	string		oldContent;
	string		newContent;
	int			index;

	if (!ifs.is_open())
		return cerr << "Failure opening file " << f1 << '\n', 1;
	if (!ofs.is_open())
		return cerr << "Failure opening file " << f2 << '\n', 1;
	getline(ifs, oldContent, '\0');
	index = oldContent.find(s1);
	while (index != -1)
	{
		newContent = oldContent.substr(0, index);
		newContent.append(s2);
		newContent.append(oldContent.substr(index + s2.length(), oldContent.length()));
		oldContent = newContent;
		index = oldContent.find(s1);
	}
	ofs << newContent;
	ifs.close();
	ofs.close();
	return 0;
}

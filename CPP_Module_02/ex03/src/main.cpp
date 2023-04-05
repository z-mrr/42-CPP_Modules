/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:47:38 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/16 15:42:57 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iomanip>

using std::cout;
using std::cin;

int	main()
{
	float	x, y;

	cout << "\nCoordenadas do vertice A:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	Point	verA(x,y);

	cout << "\nCoordenadas do vertice B:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	Point	verB(x,y);

	cout << "\nCoordenadas do vertice C:\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	Point	verC(x,y);

	while (1)
	{
		cout << "\nCoordenadas do ponto:\n";
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		Point	point(x,y);

		cout << '\n' << std::boolalpha << bsp(verA, verB, verC, point) << "\n\n";
	}
	return 0;
}

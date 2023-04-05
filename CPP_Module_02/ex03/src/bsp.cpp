/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:47:03 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/03/16 16:47:45 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
		Fórmula de coordenadas baricêntricas

	denominator: Este é o denominador comum da fórmula de coordenadas baricêntricas que aparece nos cálculos de alpha e beta. É calculado uma única vez e, em seguida, usado nas expressões subsequentes. O cálculo envolve subtrações e multiplicação de coordenadas dos vértices do triângulo.

	alpha: Este é o coeficiente que multiplica o vértice A na fórmula de coordenadas baricêntricas. É calculado dividindo a subexpressão que multiplica A na fórmula pelo denominador calculado anteriormente. A subexpressão envolve subtrações e multiplicação de coordenadas dos vértices do triângulo e coordenadas do ponto sendo testado.

	beta: Este é o coeficiente que multiplica o vértice B na fórmula de coordenadas baricêntricas. É calculado dividindo a subexpressão que multiplica B na fórmula pelo denominador calculado anteriormente. A subexpressão envolve subtrações e multiplicação de coordenadas dos vértices do triângulo e coordenadas do ponto sendo testado.

	gamma: Este é o coeficiente que multiplica o vértice C na fórmula de coordenadas baricêntricas. É calculado subtraindo a soma de alpha e beta de 1. Isso ocorre porque a soma das coordenadas baricêntricas de um ponto em um triângulo sempre será igual a 1. Se alpha e beta são positivos, gamma será sempre positivo, o que significa que o ponto está dentro do triângulo.
*/

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ax = a.getX();
	Fixed	ay = a.getY();
	Fixed	bx = b.getX();
	Fixed	by = b.getY();
	Fixed	cx = c.getX();
	Fixed	cy = c.getY();
	Fixed	px = point.getX();
	Fixed	py = point.getY();

	Fixed denominator = ((by - cy) * (ax - cx) + (cx - bx) * (ay - cy));
	Fixed alpha = ((by - cy) * (px - cx) + (cx - bx) * (py - cy)) / denominator;
	Fixed beta = ((cy - ay) * (px - cx) + (ax - cx) * (py - cy)) / denominator;
	Fixed gamma = Fixed(1) - alpha - beta;

	if (alpha >= 0 && beta >= 0 && gamma >= 0)
		return true;
	return false;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:50:19 by fporto            #+#    #+#             */
/*   Updated: 2022/10/22 02:47:29 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	printResult(bool is) {
	if (is)
		std::cout << "Point is INSIDE the triangle" << std::endl;
	else
		std::cout << "Point is OUTSIDE the triangle" << std::endl;
}

static float	sign (Point p1, Point p2, Point p3) {
	return (((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())).toFloat());
}

bool	inLine(Point const p, Point const p1, Point const p2)
{
	if (p.getX() < Fixed::min(p1.getX(), p2.getX())
		|| p.getX() > Fixed::max(p1.getX(), p2.getX())
		|| p.getY() < Fixed::min(p1.getY(), p2.getY())
		|| p.getY() > Fixed::max(p1.getY(), p2.getY()))
		return false;

	if (p2.getX() - p1.getX() == Fixed(0))
		return p.getY() >= Fixed::min(p1.getY(), p2.getY())
		|| p.getY() <= Fixed::max(p1.getY(), p2.getY());

	Fixed m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	Fixed c = p2.getY() - (m * p2.getX());

	return p.getY() == (m * p.getX()) + c;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	d1, d2, d3;
	bool	has_neg, has_pos;
	bool	result;

	if (point == a || point == b || point == c
		|| inLine(point, a, b) || inLine(point, b, c) || inLine(point, c, a)) {
			printResult(false);
			return (false);
		}

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	result = !(has_neg && has_pos);
	printResult(result);
	return (result);
}

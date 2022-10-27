/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/22 02:40:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <unistd.h>
#include <cmath>
#include "Fixed.hpp"

class	Point {

private:

	Fixed	_x;
	Fixed	_y;

public:

	Point();
	Point(const float a, const float b);
	Point(const Point& copy);
	Point& operator = (const Point& point);
	bool	operator == (const Point& point) const;
	~Point();

	Fixed	getX() const;
	void	setX(Fixed const raw);
	Fixed	getY() const;
	void	setY(Fixed const raw);


};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

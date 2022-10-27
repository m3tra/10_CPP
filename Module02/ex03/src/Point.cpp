/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2022/10/22 02:39:39 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float a, const float b) : _x(a), _y(b) {}

Point::Point(const Point& copy) {
	*this = copy;
}

Point&	Point::operator = (const Point& point) {
	this->_x = point._x;
	this->_y = point._y;
	return (*this);
}

bool	Point::operator == (const Point& point) const {
	if (this->_x == point._x && this->_y == point._y)
		return (true);
	return (false);
}

Point::~Point() {}



Fixed	Point::getX(void) const {
	return (this->_x);
}
void	Point::setX(Fixed const raw) {
	this->_x = raw;
}

Fixed	Point::getY(void) const {
	return (this->_y);
}
void	Point::setY(Fixed const raw) {
	this->_y = raw;
}

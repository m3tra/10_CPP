/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2022/10/07 21:20:43 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0) {}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

Fixed::Fixed(const int n) : _fixedPointNum(n << _fractionalBits) {}

Fixed::Fixed(const float n) {
	this->setRawBits(roundf(n * (1 << this->_fractionalBits)));
}

Fixed::~Fixed() {}



int		Fixed::getRawBits(void) const {
	return (this->_fixedPointNum);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNum = raw;
}

float	Fixed::toFloat(void) const {
	return (this->_fixedPointNum / static_cast<float>(1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->_fixedPointNum >> this->_fractionalBits);
}



std::ostream& operator << (std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}



Fixed&	Fixed::operator = (const Fixed& fixed) {
	this->_fixedPointNum = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator > (const Fixed& fixed) const {
	if (this->_fixedPointNum > fixed._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator < (const Fixed& fixed) const {
	if (this->_fixedPointNum < fixed._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator >= (const Fixed& fixed) const {
	if (this->_fixedPointNum >= fixed._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed& fixed) const {
	if (this->_fixedPointNum <= fixed._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator == (const Fixed& fixed) const {
	if (this->_fixedPointNum == fixed._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator != (const Fixed& fixed) const {
	if (this->_fixedPointNum != fixed._fixedPointNum)
		return (true);
	return (false);
}

Fixed	Fixed::operator + (const Fixed& fixed) const {
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator - (const Fixed& fixed) const {
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator * (const Fixed& fixed) const {
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator / (const Fixed& fixed) const {
	return (this->toFloat() / fixed.toFloat());
}

Fixed&	Fixed::operator ++ () {
	this->_fixedPointNum += 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int) {
	Fixed	oldValue = *this;
	this->_fixedPointNum += 1;
	return (oldValue);
}

Fixed&	Fixed::operator -- () {
	this->_fixedPointNum -= 1;
	return (*this);
}

Fixed	Fixed::operator -- (int) {
	Fixed	oldValue = *this;
	this->_fixedPointNum -= 1;
	return (oldValue);
}



Fixed&			Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}

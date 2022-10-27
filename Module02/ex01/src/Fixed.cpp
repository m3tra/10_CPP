/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2022/10/07 01:31:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n) : _fixedPointNum(n << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(n * (1 << this->_fractionalBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNum = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNum);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNum = raw;
}

float	Fixed::toFloat(void) const {
	return (this->_fixedPointNum / static_cast<float>(1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->_fixedPointNum >> this->_fractionalBits);
}

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

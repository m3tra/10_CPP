/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/07 21:17:52 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <unistd.h>
#include <cmath>

class	Fixed {

private:

	int					_fixedPointNum;
	static const int	_fractionalBits = 8;

public:

	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

	Fixed& operator= (const Fixed& fixed);

	bool	operator > (const Fixed& fixed) const;
	bool	operator < (const Fixed& fixed) const;
	bool	operator >= (const Fixed& fixed) const;
	bool	operator <= (const Fixed& fixed) const;
	bool	operator == (const Fixed& fixed) const;
	bool	operator != (const Fixed& fixed) const;

	Fixed	operator + (const Fixed& fixed) const;
	Fixed	operator - (const Fixed& fixed) const;
	Fixed	operator * (const Fixed& fixed) const;
	Fixed	operator / (const Fixed& fixed) const;

	Fixed&	operator ++ ();
	Fixed	operator ++ (int);
	Fixed&	operator -- ();
	Fixed	operator -- (int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed);

#endif

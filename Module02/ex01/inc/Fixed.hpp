/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/07 01:12:28 by fporto           ###   ########.fr       */
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

	Fixed& operator= (const Fixed& fixed);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

};

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed);

#endif

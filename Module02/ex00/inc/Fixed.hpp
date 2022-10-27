/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/06 18:44:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <unistd.h>

class	Fixed {

private:

	int					_fixedPointNum;
	static const int	_fractionalBits = 8;

public:

	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed& operator= (const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

#endif

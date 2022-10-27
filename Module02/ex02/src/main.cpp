/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/07 21:18:10 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// static void tests()
// {
// 	Fixed a ( 0 );
// 	Fixed b ( 25 );
// 	Fixed c ( 50 );

// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c: " << c << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b > a: " << (b > a) << std::endl;
// 	std::cout << "b > b: " << (b > b) << std::endl;
// 	std::cout << "b > c: " << (b > c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b < a: " << (b < a) << std::endl;
// 	std::cout << "b < b: " << (b < b) << std::endl;
// 	std::cout << "b < c: " << (b < c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b >= a: " << (b >= a) << std::endl;
// 	std::cout << "b >= b: " << (b >= b) << std::endl;
// 	std::cout << "b >= c: " << (b >= c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b <= a: " << (b <= a) << std::endl;
// 	std::cout << "b <= b: " << (b <= b) << std::endl;
// 	std::cout << "b <= c: " << (b <= c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b == a: " << (b == a) << std::endl;
// 	std::cout << "b == b: " << (b == b) << std::endl;
// 	std::cout << "b == c: " << (b == c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b != a: " << (b != a) << std::endl;
// 	std::cout << "b != b: " << (b != b) << std::endl;
// 	std::cout << "b != c: " << (b != c) << std::endl;


// 	std::cout << std::endl;


// 	std::cout << "b + a: " << (b + a) << std::endl;
// 	std::cout << "b + b: " << (b + b) << std::endl;
// 	std::cout << "b + c: " << (b + c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b - a: " << (b - a) << std::endl;
// 	std::cout << "b - b: " << (b - b) << std::endl;
// 	std::cout << "b - c: " << (b - c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b * a: " << (b * a) << std::endl;
// 	std::cout << "b * b: " << (b * b) << std::endl;
// 	std::cout << "b * c: " << (b * c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "b / a: " << (b / a) << std::endl;
// 	std::cout << "b / b: " << (b / b) << std::endl;
// 	std::cout << "b / c: " << (b / c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "a++: " << (a++) << std::endl;
// 	std::cout << "b++: " << (b++) << std::endl;
// 	std::cout << "c++: " << (c++) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "++a: " << (++a) << std::endl;
// 	std::cout << "++b: " << (++b) << std::endl;
// 	std::cout << "++c: " << (++c) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "a--: " << (a--) << std::endl;
// 	std::cout << "b--: " << (b--) << std::endl;
// 	std::cout << "c--: " << (c--) << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "--a: " << (--a) << std::endl;
// 	std::cout << "--b: " << (--b) << std::endl;
// 	std::cout << "--c: " << (--c) << std::endl;
// }

int main( void ) {
	// tests();

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

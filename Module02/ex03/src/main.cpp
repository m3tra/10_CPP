/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/22 02:46:12 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

void	tests(void) {

	Point	a(0, 0);
	Point	b(7, 0);
	Point	c(0, 7);
	Point	point(5, 5);

	std::cout << "A(0,0) B(7,0), C(0,7), P(5,5)" << std::endl;

	std::cout << "C" << std::endl;
	std::cout << "|\\" << std::endl;
	std::cout << "| \\ ." << std::endl;
	std::cout << "|  \\" << std::endl;
	std::cout << "|   \\" << std::endl;
	std::cout << "|    \\" << std::endl;
	std::cout << "|     \\" << std::endl;
	std::cout << "|______\\" << std::endl;
	std::cout << "A       B" << std::endl;

	bsp(a, b, c, point);

	std::cout << std::endl;

	a.setX(0);
	a.setY(0);
	b.setX(7);
	b.setY(0);
	c.setX(0);
	c.setY(7);
	point.setX(1);
	point.setY(1);

	std::cout << "A(0,0) B(7,0), C(0,7), P(1,1)" << std::endl;

	std::cout << "C" << std::endl;
	std::cout << "|\\" << std::endl;
	std::cout << "| \\" << std::endl;
	std::cout << "|  \\" << std::endl;
	std::cout << "|   \\" << std::endl;
	std::cout << "|    \\" << std::endl;
	std::cout << "| .   \\" << std::endl;
	std::cout << "|______\\" << std::endl;
	std::cout << "A       B" << std::endl;

	bsp(a, b, c, point);

	std::cout << std::endl;

	a.setX(0);
	a.setY(0);
	b.setX(7);
	b.setY(0);
	c.setX(0);
	c.setY(7);
	point.setX(0);
	point.setY(1);

	std::cout << "A(0,0) B(7,0), C(0,7), P(0,1)" << std::endl;

	std::cout << "C" << std::endl;
	std::cout << "|\\" << std::endl;
	std::cout << "| \\" << std::endl;
	std::cout << "|  \\" << std::endl;
	std::cout << "|   \\" << std::endl;
	std::cout << "|    \\" << std::endl;
	std::cout << ".     \\" << std::endl;
	std::cout << "|______\\" << std::endl;
	std::cout << "A       B" << std::endl;

	bsp(a, b, c, point);

	std::cout << std::endl;

	a.setX(0);
	a.setY(0);
	b.setX(14);
	b.setY(0);
	c.setX(6);
	c.setY(7);
	point.setX(3);
	point.setY(5);

	std::cout << "      C" << std::endl;
	std::cout << "      /\\" << std::endl;
	std::cout << "   . /  \\" << std::endl;
	std::cout << "    /    \\" << std::endl;
	std::cout << "   /      \\" << std::endl;
	std::cout << "  /        \\" << std::endl;
	std::cout << " /          \\" << std::endl;
	std::cout << "/____________\\" << std::endl;
	std::cout << "A             B" << std::endl;

	std::cout << "A(0,0) B(14,0), C(6,7), P(3,5)" << std::endl;

	bsp(a, b, c, point);

	std::cout << std::endl;

	a.setX(0);
	a.setY(0);
	b.setX(14);
	b.setY(0);
	c.setX(6);
	c.setY(7);
	point.setX(0);
	point.setY(4);

	std::cout << "      C" << std::endl;
	std::cout << "      /\\" << std::endl;
	std::cout << "     /  \\" << std::endl;
	std::cout << "    /    \\" << std::endl;
	std::cout << "   /      \\" << std::endl;
	std::cout << "  /        \\" << std::endl;
	std::cout << " /          \\" << std::endl;
	std::cout << "/___.________\\" << std::endl;
	std::cout << "A             B" << std::endl;

	std::cout << "A(0,0) B(14,0), C(6,7), P(0,4)" << std::endl;

	bsp(a, b, c, point);
}

int	main( void ) {
	tests();
	return 0;
}

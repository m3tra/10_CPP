/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:06 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 16:34:39 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	std::cout << ORANGE "Joe" WHITE << std::endl;

	try {
		Bureaucrat	joe = Bureaucrat("Joe", 30);

		std::cout << joe << std::endl;
		joe.promote();
		std::cout << joe << std::endl;
		joe.demote();
		std::cout << joe << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << ORANGE "John" WHITE << std::endl;

	try {
		Bureaucrat	john = Bureaucrat("John", 1);

		std::cout << john << std::endl;
		john.promote();
		std::cout << john << std::endl;
		john.demote();
		std::cout << john << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << ORANGE "Gui" WHITE << std::endl;

	try {
		Bureaucrat	gui = Bureaucrat("Gui", 150);

		std::cout << gui << std::endl;
		gui.promote();
		std::cout << gui << std::endl;
		gui.demote();
		std::cout << gui << std::endl;
		gui.demote();
		std::cout << gui << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << ORANGE "Joel" WHITE << std::endl;

	try {
		Bureaucrat	joel = Bureaucrat("Joel", 151);

		std::cout << joel << std::endl;
		joel.promote();
		std::cout << joel << std::endl;
		joel.demote();
		std::cout << joel << std::endl;
		joel.demote();
		std::cout << joel << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << ORANGE "Jason" WHITE << std::endl;

	try {
		Bureaucrat	jason = Bureaucrat("Jason", 0);

		std::cout << jason << std::endl;
		jason.promote();
		std::cout << jason << std::endl;
		jason.demote();
		std::cout << jason << std::endl;
		jason.demote();
		std::cout << jason << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

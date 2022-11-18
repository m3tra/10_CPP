/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:06 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 05:23:41 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	std::cout << ORANGE "Joe" WHITE << std::endl;

	try {
		Bureaucrat	joe = Bureaucrat("Joe", 57);
		Form		e42 = Form("E42", 42, 21);

		std::cout << std::endl;

		joe.signForm(e42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "John" WHITE << std::endl;

	try {
		Bureaucrat	john = Bureaucrat("John", 30);
		Form		e4sy = Form("E4SY", 150, 150);

		std::cout << std::endl;

		john.signForm(e4sy);
		john.signForm(e4sy);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "Jane" WHITE " and " ORANGE "Jack" WHITE << std::endl;

	try {
		Bureaucrat	jane = Bureaucrat("Jane", 100);
		Bureaucrat	jack = Bureaucrat("Jack", 30);
		Form		h4rd = Form("H4RD", 70, 150);

		std::cout << std::endl;

		jane.signForm(h4rd);
		jack.signForm(h4rd);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return 0;
}

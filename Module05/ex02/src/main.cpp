/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:06 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:44:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {

	std::cout << ORANGE "Joe/Joh" WHITE << std::endl;
	std::cout << ORANGE "PresidentialPardonForm" WHITE << std::endl;

	try {
		Bureaucrat	joe = Bureaucrat("Joe", 57);
		Bureaucrat	joh = Bureaucrat("Joh", 3);
		PresidentialPardonForm	e42 = PresidentialPardonForm("Fernando Mendes");

		std::cout << std::endl;

		joe.signForm(e42);
		joe.executeForm(e42);
		joh.signForm(e42);
		joh.executeForm(e42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "John" WHITE << std::endl;
	std::cout << ORANGE "RobotomyRequestForm" WHITE << std::endl;

	try {
		Bureaucrat	john = Bureaucrat("John", 30);
		RobotomyRequestForm	e4sy = RobotomyRequestForm("Maria Leal");

		std::cout << std::endl;

		john.executeForm(e4sy);
		john.signForm(e4sy);
		john.signForm(e4sy);
		john.executeForm(e4sy);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "Jane/Jack" WHITE << std::endl;
	std::cout << ORANGE "ShrubberyCreationForm" WHITE << std::endl;

	try {
		Bureaucrat	jane = Bureaucrat("Jane", 100);
		Bureaucrat	jack = Bureaucrat("Jack", 30);
		ShrubberyCreationForm	h4rd = ShrubberyCreationForm("Trees");

		std::cout << std::endl;

		jane.executeForm(h4rd);
		jack.executeForm(h4rd);
		jane.signForm(h4rd);
		jack.signForm(h4rd);
		jane.executeForm(h4rd);
		jack.executeForm(h4rd);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}


	return 0;
}

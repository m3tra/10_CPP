/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:06 by fporto            #+#    #+#             */
/*   Updated: 2022/11/19 12:39:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
	std::cout << ORANGE "Joe/Joh" WHITE << std::endl;
	std::cout << ORANGE "PresidentialPardonForm" WHITE << std::endl;

	try {
		Bureaucrat	joe = Bureaucrat("Joe", 57);
		Bureaucrat	joh = Bureaucrat("Joh", 3);
		Intern	someRandomIntern;
		Form*	form = someRandomIntern.makeForm("presidential pardon", "Fernando Mendes");
		if (!form)
			throw(Intern::UnknownFormException());

		std::cout << std::endl;

		joe.signForm(*form);
		joe.executeForm(*form);
		joh.signForm(*form);
		joh.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "John" WHITE << std::endl;
	std::cout << ORANGE "RobotomyRequestForm" WHITE << std::endl;

	try {
		Bureaucrat	john = Bureaucrat("John", 30);
		Intern	someRandomIntern;
		Form*	form = someRandomIntern.makeForm("robotomy request", "Maria Leal");
		if (!form)
			throw(Intern::UnknownFormException());

		std::cout << std::endl;

		john.executeForm(*form);
		john.signForm(*form);
		john.signForm(*form);
		john.executeForm(*form);
		delete form;
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
		Intern	someRandomIntern;
		Form*	form = someRandomIntern.makeForm("shrubbery creation", "Trees");
		if (!form)
			throw(Intern::UnknownFormException());

		std::cout << std::endl;

		jane.executeForm(*form);
		jack.executeForm(*form);
		jane.signForm(*form);
		jack.signForm(*form);
		jane.executeForm(*form);
		jack.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << ORANGE "Jason/Jerry" WHITE << std::endl;
	std::cout << ORANGE "Unknown Form" WHITE << std::endl;

	try {
		Bureaucrat	jaosn = Bureaucrat("Jason", 100);
		Bureaucrat	jerry = Bureaucrat("Jerry", 30);
		Intern	someRandomIntern;
		Form*	form = someRandomIntern.makeForm("building demolition", "Downtown");
		if (!form)
			throw(Intern::UnknownFormException());

		std::cout << std::endl;

		jaosn.executeForm(*form);
		jerry.executeForm(*form);
		jaosn.signForm(*form);
		jerry.signForm(*form);
		jaosn.executeForm(*form);
		jerry.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return 0;
}

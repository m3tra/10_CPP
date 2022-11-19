/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2022/11/19 12:39:55 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

// Intern::Intern(const string& name, int grade) throw(std::exception) : _name(name) {
// 	if (grade < 1)
// 		throw (GradeTooHighException("Grade is too high"));
// 	else if (grade > 150)
// 		throw (GradeTooLowException("Grade is too low"));

// 	_grade = grade;

// 	std::cout << PURPLE "Default constructor called for ";
// 	std::cout << YELLOW "[Intern] " WHITE "of name " BLUE << _name << WHITE;
// 	std::cout << " and grade " GREEN << _grade << WHITE;
// 	std::cout << std::endl;
// }

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[Intern]" WHITE;
	std::cout << std::endl;
}

Intern& Intern::operator = (const Intern& other) {
	(void)other;
	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[Intern]" WHITE;
	std::cout << std::endl;

	return *this;
}

Intern::~Intern() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[Intern]" WHITE;
	std::cout << std::endl;
}



Intern::UnknownFormException::UnknownFormException() {}

const char*	Intern::UnknownFormException::what() const throw() {
	return ("Unknown form");
}



const string Intern::_knownForms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Form*	Intern::makeForm(const string name, const string target) const {
	size_t	i;

	for (i = 0; i < 3; i++)
		if (_knownForms[i] == name)
			break;

	switch (i) {
		case 0:
			std::cout << "Intern creates " BLUE + name + WHITE " form" << std::endl;
			return new PresidentialPardonForm(target);
		case 1:
			std::cout << "Intern creates " BLUE + name + WHITE " form" << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " BLUE + name + WHITE " form" << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			return NULL;
	}
}

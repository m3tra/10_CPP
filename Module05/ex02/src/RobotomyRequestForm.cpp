/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:45:15 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(string target) : Form(target + "_Request", 72, 45), _target(target) {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[RobotomyRequestForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other), _target(other.getTarget()) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[RobotomyRequestForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& other) {
	this->_target = other.getTarget();

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[RobotomyRequestForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[RobotomyRequestForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}



string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}



void	RobotomyRequestForm::_execute(Bureaucrat const & executor) const {
	(void) executor;
	std::cout << YELLOW "* drilling noises *" << std::endl;
	std::cout << "Robotomy on ";
	std::cout << BLUE << this->getTarget() << YELLOW;
	if (std::rand() % 2)
		std::cout << " has succeded" << WHITE;
	else
		std::cout << " has failed" << WHITE;
	std::cout << std::endl;
}



std::ostream&	operator << (std::ostream& out, const RobotomyRequestForm& form) {
	out << BLUE << form.getName() << WHITE;
	out << ", form with grade required to" << std::endl;
	out << "        sign ";
	out << GREEN << form.getGradeToSign() << WHITE << std::endl;
	out << "        execute ";
	out << GREEN << form.getGradeToExec() << WHITE << std::endl;
	out << "        target ";
	out << GREEN << form.getTarget() << WHITE;
	return out;
}

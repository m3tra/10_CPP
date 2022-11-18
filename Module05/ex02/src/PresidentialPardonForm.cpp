/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:44:44 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) : Form(target + "_Pardon", 25, 5), _target(target) {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[PresidentialPardonForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other), _target(other.getTarget()) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[PresidentialPardonForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other) {
	this->_target = other.getTarget();

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[PresidentialPardonForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[PresidentialPardonForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}



string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}



void	PresidentialPardonForm::_execute(Bureaucrat const & executor) const {
	(void) executor;
	std::cout << BLUE << this->getTarget() << WHITE;
	std::cout << YELLOW " has been pardoned by Zaphod Beeblebrox" WHITE;
	std::cout << std::endl;
}



std::ostream&	operator << (std::ostream& out, const PresidentialPardonForm& form) {
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

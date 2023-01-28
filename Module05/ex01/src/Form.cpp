/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 16:48:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const string& name, int gradeToSign, int gradeToExec) throw(std::exception) \
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1)
		throw (GradeTooHighException("Grade required to sign is too high"));
	else if (gradeToSign > 150)
		throw (GradeTooLowException("Grade required to sign is too low"));
	else if (gradeToExec < 1)
		throw (GradeTooHighException("Grade required to execute is too high"));
	else if (gradeToExec > 150)
		throw (GradeTooLowException("Grade required to execute is too low"));

	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[Form] " BLUE << _name << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

Form::Form(const Form& other) \
		: _name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[Form] " BLUE << _name << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

Form& Form::operator = (const Form& other) {
	this->_isSigned = other._isSigned;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[Form] " BLUE << _name << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;

	return *this;
}

Form::~Form() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[Form] " BLUE << _name << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}



Form::GradeTooHighException::GradeTooHighException(const char* context) : _context(context) {}

Form::GradeTooLowException::GradeTooLowException(const char* context) : _context(context) {}

const char*	Form::GradeTooHighException::what() const throw() {
	return this->_context;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return this->_context;
}



const string	Form::getName() const{
	return this->_name;
}

int				Form::getGradeToSign() const{
	return this->_gradeToSign;
}

int				Form::getGradeToExec() const{
	return this->_gradeToExec;
}

bool			Form::isSigned() const {
	return this->_isSigned;
}



void			Form::sign(Bureaucrat& bureaucrat) throw (GradeTooLowException) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (GradeTooLowException(RED "grade too low to sign" WHITE));
	this->_isSigned = true;
}



std::ostream&	operator << (std::ostream& out, const Form& form) {
	out << BLUE << form.getName() << WHITE;
	out << ", ";
	out << YELLOW "form" WHITE;
	out << " with grade required to" << std::endl;
	out << "        sign ";
	out << GREEN << form.getGradeToSign() << WHITE << std::endl;
	out << "        execute ";
	out << GREEN << form.getGradeToExec() << WHITE;
	return out;
}

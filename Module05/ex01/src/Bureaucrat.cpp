/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 07:43:23 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const string& name, int grade) throw(std::exception) : _name(name) {
	if (grade < 1)
		throw (GradeTooHighException("Grade is too high"));
	else if (grade > 150)
		throw (GradeTooLowException("Grade is too low"));

	_grade = grade;

	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[Bureaucrat] " WHITE "of name " BLUE << _name << WHITE;
	std::cout << " and grade " GREEN << _grade << WHITE;
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[Bureaucrat] " WHITE "of name " BLUE << _name << WHITE;
	std::cout << " and grade " GREEN << _grade << WHITE;
	std::cout << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
	this->_grade = other._grade;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[Bureaucrat] " WHITE "of name " BLUE << _name << WHITE;
	std::cout << " and grade " GREEN << _grade << WHITE;
	std::cout << std::endl;

	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[Bureaucrat] " WHITE "of name " BLUE << _name << WHITE;
	std::cout << " and grade " GREEN << _grade << WHITE;
	std::cout << std::endl;
}



Bureaucrat::GradeTooHighException::GradeTooHighException(const char* context) : _context(context) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* context) : _context(context) {}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return this->_context;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return this->_context;
}



const string	Bureaucrat::getName() const{
	return this->_name;
}

int				Bureaucrat::getGrade() const{
	return this->_grade;
}



void			Bureaucrat::promote() throw (GradeTooHighException) {
	if (this->getGrade() == 1)
		throw GradeTooHighException("Already has highest grade");
	this->_grade--;
}

void			Bureaucrat::demote() throw (GradeTooLowException) {
	if (this->getGrade() == 150)
		throw GradeTooLowException("Already has lowest grade");
	this->_grade++;
}

void			Bureaucrat::signForm(Form& form) {
	if (form.isSigned()) {
		std::cout << BLUE << *this << std::endl;
		std::cout << RED "couldn't sign" << std::endl;
		std::cout << "    " << form << std::endl;
		std::cout << "    because" << std::endl;
		std::cout << "        it was already signed" << std::endl << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
		std::cout << BLUE << *this << std::endl;
		std::cout << GREEN "signed" << std::endl;
		std::cout << "    " << form << std::endl << std::endl;
	}
	catch(Form::GradeTooLowException & e) {
		std::cout << BLUE << *this << std::endl;
		std::cout << RED "couldn't sign" << std::endl;
		std::cout << "    " << form << std::endl;
		std::cout << "    because" << std::endl;
		std::cout << "        " << e.what() << std::endl << std::endl;
	}
}



std::ostream&	operator << (std::ostream& out, const Bureaucrat& bureaucrat) {
	out << BLUE << bureaucrat.getName() << WHITE;
	out << ", bureaucrat grade ";
	out << GREEN << bureaucrat.getGrade() << WHITE;
	return out;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 10:09:59 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "color.hpp"
#include "Form.hpp"

using std::string;

class Form;

class Bureaucrat {

private:

	const string	_name;
	int				_grade;

public:

	class GradeTooHighException : public std::exception {
		private:
			const char*	_context;
		public:
			GradeTooHighException(const char* context);
			virtual const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
		private:
			const char*	_context;
		public:
			GradeTooLowException(const char* context);
			virtual const char * what () const throw ();
	};

	Bureaucrat(const string& name, int grade) throw(std::exception);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator = (const Bureaucrat& other);
	virtual ~Bureaucrat();

	const string	getName() const;
	int				getGrade() const;

	void			promote() throw (GradeTooHighException);
	void			demote() throw (GradeTooLowException);

	void			signForm(Form& form);

	void			executeForm(Form const & form);

};

std::ostream&	operator << (std::ostream& out, const Bureaucrat& bureaucrat);

#endif

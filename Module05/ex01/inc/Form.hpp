/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 04:07:52 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "color.hpp"
#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;

class Form {

private:

	const string	_name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExec;

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

	Form(const string& name, int gradeToSign, int gradeToExec) throw(std::exception);
	Form(const Form& other);
	Form& operator = (const Form& other);
	virtual ~Form();

	const string	getName() const;
	int				getGradeToSign() const;
	int				getGradeToExec() const;
	bool			isSigned() const;

	void			beSigned(Bureaucrat& bureaucrat) throw (GradeTooLowException);

};

std::ostream&	operator << (std::ostream& out, const Form& form);

#endif

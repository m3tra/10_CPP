/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 16:28:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "color.hpp"

using std::string;

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

};

std::ostream&	operator << (std::ostream& out, const Bureaucrat& bureaucrat);

#endif

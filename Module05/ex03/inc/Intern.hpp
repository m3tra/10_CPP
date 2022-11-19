/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/19 12:37:30 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "color.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::string;

class Form;

class Intern {

private:

	static const	string _knownForms[3];

public:

	class UnknownFormException : public std::exception {
		public:
			UnknownFormException();
			virtual const char * what () const throw ();
	};

	Intern();
	Intern(const Intern& other);
	Intern& operator = (const Intern& other);
	virtual ~Intern();

	Form*	makeForm(const string name, const string target) const;

};

#endif

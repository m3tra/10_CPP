/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:29:17 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

using std::string;

class ShrubberyCreationForm : public Form {

private:

	string	_target;
	void	_execute(Bureaucrat const & executor) const;

public:

	ShrubberyCreationForm(string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

	string	getTarget() const;

};

std::ostream&	operator << (std::ostream& out, const ShrubberyCreationForm& form);

#endif

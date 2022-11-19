/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:29:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

using std::string;

class PresidentialPardonForm : public Form {

private:

	string	_target;
	void	_execute(Bureaucrat const & executor) const;

public:

	PresidentialPardonForm(string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	string	getTarget() const;

};

std::ostream&	operator << (std::ostream& out, const PresidentialPardonForm& form);

#endif

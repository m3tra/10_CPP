/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:26 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:29:42 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

using std::string;

class RobotomyRequestForm : public Form {

private:

	string	_target;
	void	_execute(Bureaucrat const & executor) const;

public:

	RobotomyRequestForm(string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

	string	getTarget() const;

};

std::ostream&	operator << (std::ostream& out, const RobotomyRequestForm& form);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:39:15 by fporto            #+#    #+#             */
/*   Updated: 2022/11/18 11:46:17 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form(target + "_Creation", 145, 137), _target(target) {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[ShrubberyCreationForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other), _target(other.getTarget()) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[ShrubberyCreationForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other) {
	this->_target = other.getTarget();

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[ShrubberyCreationForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[ShrubberyCreationForm] " WHITE "of name " BLUE << this->getName() << WHITE;
	std::cout << ", grade required to sign " GREEN << this->getGradeToSign() << WHITE;
	std::cout << " and grade required to execute " GREEN << this->getGradeToExec() << WHITE;
	std::cout << std::endl;
}



string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}



void	ShrubberyCreationForm::_execute(Bureaucrat const & executor) const {
	(void) executor;
	std::ofstream treeFile(this->getTarget().append("_shrubbery").c_str());
	treeFile << "\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
\n";
	treeFile.close();
}



std::ostream&	operator << (std::ostream& out, const ShrubberyCreationForm& form) {
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

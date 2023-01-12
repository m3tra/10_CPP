/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:26:06 by fporto            #+#    #+#             */
/*   Updated: 2023/01/12 19:07:08 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	_Empty = true;
}

Contact::~Contact() {}

Contact::Contact(string FirstName, string LastName, string Nickname, \
	string PhoneNumber, string Secret) {
		_Empty = false;
		_FirstName = FirstName;
		_LastName = LastName;
		_Nickname = Nickname;
		_PhoneNumber = PhoneNumber;
		_Secret = Secret;
		_CreationTime = std::time(0);
}

bool	Contact::isEmpty() {
	return (this->_Empty);
}

void	Contact::setFirstName(string FirstName) {
	this->_Empty = false;
	this->_FirstName = FirstName;
}

void	Contact::setLastName(string LastName) {
	this->_LastName = LastName;
}

void	Contact::setNickname(string Nickname) {
	this->_Nickname = Nickname;
}

bool	Contact::setPhoneNumber(string PhoneNumber) {
	if (!PhoneNumber.compare(""))
		return (false);
	for (size_t i = 0; i < PhoneNumber.length(); i++)
		if (!isdigit(PhoneNumber[i]))
			return (false);
	this->_PhoneNumber = PhoneNumber;
	return (true);
}

void	Contact::setSecret(string Secret) {
	this->_Secret = Secret;
}

void	Contact::setCreationTime(std::time_t CreationTime) {
	this->_CreationTime = CreationTime;
}




string	Contact::getFirstName() {
	return (this->_FirstName);
}

string	Contact::getLastName() {
	return (this->_LastName);
}

string	Contact::getNickname() {
	return (this->_Nickname);
}

string	Contact::getPhoneNumber() {
	return (this->_PhoneNumber);
}

string	Contact::getSecret() {
	return (this->_Secret);
}

int		Contact::getCreationTime() {
	return (this->_CreationTime);
}

void	Contact::displayContact() {
	std::cout << "First Name: " << this->_FirstName << std::endl;
	std::cout << "Last Name: " << this->_LastName << std::endl;
	std::cout << "Nickname: " << this->_Nickname << std::endl;
	std::cout << "Phone Number: " << this->_PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_Secret << std::endl;
}

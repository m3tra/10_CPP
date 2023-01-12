/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:26:06 by fporto            #+#    #+#             */
/*   Updated: 2023/01/12 19:12:04 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact	PhoneBook::getContact(int index) {
	return (this->ContactsList[index]);
}

bool	PhoneBook::isEmpty() {
	for (int i = 0; i < LIST_SIZE; i++)
		if (!this->ContactsList[i].isEmpty())
			return (false);
	return (true);
}

bool	PhoneBook::hasEmptyContact() {
	for (int i = 0; i < LIST_SIZE; i++)
		if (this->ContactsList[i].isEmpty())
			return (true);
	return (false);
}

int		PhoneBook::getEmptyIndex() {
	for (int i = 0; i < LIST_SIZE; i++)
		if (this->ContactsList[i].isEmpty())
			return (i);
	return (-1);
}

int		PhoneBook::getOldestIndex() {
	int	OldestIndex = 0;
	int	OldestTime = this->ContactsList[0].getCreationTime();
	int	TmpTime;

	for (int i = 1; i < LIST_SIZE; i++) {
		TmpTime = this->ContactsList[i].getCreationTime();
		if (TmpTime < OldestTime) {
			OldestTime = TmpTime;
			OldestIndex = i;
		}
	}
	return (OldestIndex);
}

void	PhoneBook::insertContact(Contact NewContact) {
	if (this->hasEmptyContact())
		this->ContactsList[this->getEmptyIndex()] = NewContact;
	else {
		this->ContactsList[this->getOldestIndex()] = NewContact;
	}
}

static string	Truncate(string BigString) {
	if (BigString.length() > 10)
	{
		BigString.resize(9);
		BigString.append(".");
	}
	return (BigString);
}

void	PhoneBook::displayContacts() {
	Contact	Tmp;

	for (int i = 0; i < LIST_SIZE; i++) {
		Tmp = this->ContactsList[i];

		if (!Tmp.isEmpty()) {
			std::cout << std::setw(10) << i << " | ";
			std::cout << std::setw(10) << Truncate(Tmp.getFirstName()) << " | ";
			std::cout << std::setw(10) << Truncate(Tmp.getLastName()) << " | ";
			std::cout << std::setw(10) << Truncate(Tmp.getNickname()) << std::endl;
		}
	}
}

int	PhoneBook::getSize() {
	int	n = this->getEmptyIndex();
	if (n == -1)
		return (LIST_SIZE);
	return (n);
}

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

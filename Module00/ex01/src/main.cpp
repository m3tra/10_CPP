/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:33:55 by fporto            #+#    #+#             */
/*   Updated: 2022/07/31 22:47:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

static string read(string prompt)
{
	string	input;

	std::cout << prompt;
	getline(std::cin, input);
	return (input);
}

static Contact	CreateContact() {
	Contact	NewContact;

	string	FirstName;
	string	LastName;
	string	Nickname;
	string	PhoneNumber;
	string	Secret;

	std::cout << "Adding new contact:" << std::endl;

	while (!FirstName.compare(""))
		FirstName = read("First name: ");

	while (!LastName.compare(""))
		LastName = read("Last name: ");

	while (!Nickname.compare(""))
		Nickname = read("Nickname: ");

	while (!NewContact.setPhoneNumber(PhoneNumber))
		PhoneNumber = read("Phone Number(digits only): ");

	while (!Secret.compare(""))
		Secret = read("Darkest Secret: ");

	NewContact = Contact(FirstName, LastName, Nickname, PhoneNumber, Secret);

	return (NewContact);
}

static void	SearchContact(PhoneBook	list) {
	string	selection;
	int		index;

	if (list.isEmpty())
		std::cout << "Contact list empty.\n";
	else {
		list.displayContacts();
		std::cout << std::endl;

		std::cout << "Select contact to display: ";
		std::cin >> index;
		while (index < 0 || (index >= list.getSize())) {
			std::cout << "Contact #" << index << " does not exist, choose again: ";
			std::cin >> index;
		}
		std::cout << std::endl;
		list.getContact(index).displayContact();
		std::cout << std::endl;
	}
}

int		main(void) {
	PhoneBook	list;
	string		input;

	std::cout << "Welcome to the PhoneBook, do you wish to:\n";

	while (input.compare("EXIT")) {
		input = read("ADD a contact, SEARCH for one, or EXIT?\n");
		if (!input.compare("ADD")) {
			list.insertContact(CreateContact());
			std::cout << "Contact added.\n";
		}
		else if (!input.compare("SEARCH")) {
			SearchContact(list);
		}
	}
	return (0);
}

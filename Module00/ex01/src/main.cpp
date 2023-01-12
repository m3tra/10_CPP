/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:33:55 by fporto            #+#    #+#             */
/*   Updated: 2023/01/12 18:40:51 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

// static string read(string prompt)
// {
// 	string	input;

// 	std::cout << prompt;
// 	getline(std::cin, input);
// 	return (input);
// }

static Contact	CreateContact() {
	Contact	NewContact;

	string	FirstName;
	string	LastName;
	string	Nickname;
	string	PhoneNumber;
	string	Secret;

	std::cout << "Adding new contact" << std::endl;

	while (!FirstName.compare("")) {
		std::cout << "First name: ";
		std::cin >> FirstName;
	}

	while (!LastName.compare("")) {
		std::cout << "Last name: ";
		std::cin >> LastName;
	}

	while (!Nickname.compare("")) {
		std::cout << "Nickname: ";
		std::cin >> Nickname;
	}

	while (!NewContact.setPhoneNumber(PhoneNumber)) {
		std::cout << "Phone Number(digits only): ";
		std::cin >> PhoneNumber;
	}

	while (!Secret.compare("")) {
		std::cout << "Darkest Secret: ";
		std::cin >> Secret;
	}

	NewContact = Contact(FirstName, LastName, Nickname, PhoneNumber, Secret);

	return (NewContact);
}

static void	SearchContact(PhoneBook	list) {
	string	selection;
	int		index;

	if (list.isEmpty())
		std::cout << "Contact list empty." << std::endl << std::endl;
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
		std::cout << "\n";
	}
}

int		main(void) {
	PhoneBook	list;
	string		input;

	std::cout << "Welcome to the PhoneBook, do you wish to:" << std::endl;

	while (true) {
		std::cout << "ADD a contact, SEARCH for one, or EXIT?" << std::endl;
		std::cin >> input;
		if (!input.compare("ADD")) {
			list.insertContact(CreateContact());
			std::cout << "Contact added." << std::endl << std::endl;
		}
		else if (!input.compare("SEARCH")) {
			SearchContact(list);
		}
		else if (!input.compare("EXIT"))
			break;
	}
	return (0);
}

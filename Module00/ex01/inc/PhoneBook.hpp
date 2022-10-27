/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:28:04 by fporto            #+#    #+#             */
/*   Updated: 2022/07/30 22:10:15 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define LIST_SIZE 8

class PhoneBook {

private:
	Contact	ContactsList[LIST_SIZE];

public:
	Contact getContact(int index);

	bool	isEmpty();

	bool	hasEmptyContact();
	int		getEmptyIndex();
	int		getOldestIndex();
	void	insertContact(Contact NewContact);
	int		getSize();

	void	displayContacts();

	PhoneBook();
	~PhoneBook();
};

#endif

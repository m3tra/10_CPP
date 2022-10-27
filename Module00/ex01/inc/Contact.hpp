/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:19:13 by fporto            #+#    #+#             */
/*   Updated: 2022/07/30 22:39:48 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <ctime>

using std::string;

class Contact {

private:
	bool	_Empty;
	string	_FirstName;
	string	_LastName;
	string	_Nickname;
	string	_PhoneNumber;
	string	_Secret;
	std::time_t	_CreationTime;

public:

	bool	isEmpty();

	void	setFirstName(string FirstName);
	void	setLastName(string LastName);
	void	setNickname(string Nickname);
	bool	setPhoneNumber(string PhoneNumber);
	void	setSecret(string Secret);

	string	getFirstName();
	string	getLastName();
	string	getNickname();
	string	getPhoneNumber();
	string	getSecret();
	int		getCreationTime();

	void	displayContact();

	Contact(string FirstName, string LastName, string Nickname, \
		string PhoneNumber, string Secret);
	Contact();
	~Contact();
};

#endif

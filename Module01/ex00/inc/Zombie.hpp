/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:30:00 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 03:46:56 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::string;

class Zombie {

private:

	string	_name;

public:

	void	announce(void);

	void	setName(string name);

	Zombie();
	~Zombie();
};

Zombie*	newZombie(string name);
void	randomChump(string name);

#endif

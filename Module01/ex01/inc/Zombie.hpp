/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:30:51 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 05:09:51 by fporto           ###   ########.fr       */
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
	Zombie(string name);
	~Zombie();
};

Zombie*	zombieHorde(int N, string name);

#endif

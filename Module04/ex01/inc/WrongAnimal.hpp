/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/10/31 06:04:11 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

using std::string;

class WrongAnimal {

protected:

	string	type;

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator = (const WrongAnimal& other);
	virtual ~WrongAnimal();

	string	getType() const;

	void	makeSound() const;

};

#endif

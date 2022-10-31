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

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

using std::string;

class Animal {

protected:

	string	type;

public:

	Animal();
	Animal(const Animal& other);
	Animal& operator = (const Animal& other);
	virtual ~Animal();

	string			getType() const;

	virtual void	makeSound() const;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/12 06:49:02 by fporto           ###   ########.fr       */
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
	// Protected default constructor makes class not instantiable by
	// itself, serving only as a base class to another one
	Animal();

public:

	Animal(const Animal& other);
	Animal& operator = (const Animal& other);
	virtual ~Animal();

	string			getType() const;

	virtual void	makeSound() const;

};

#endif

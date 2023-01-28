/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 13:43:34 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

using std::string;

class AAnimal {

protected:

	string	type;
	// Protected default constructor makes class not instantiable by
	// itself, serving only as a base class to another one
	AAnimal();

public:

	AAnimal(const AAnimal& other);
	AAnimal& operator = (const AAnimal& other);
	virtual ~AAnimal();

	string			getType() const;

	virtual void	makeSound() const;

};

#endif

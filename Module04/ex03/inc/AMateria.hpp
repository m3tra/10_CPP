/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 15:27:52 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "ICharacter.hpp"

using std::string;

class ICharacter;

class AMateria {

protected:

	string	_type;
	// Protected default constructor makes class not instantiable by
	// itself, serving only as a base class to another one
	AMateria();

public:

	AMateria(string const & type);
	AMateria(const AMateria& other);
	AMateria& operator = (const AMateria& other);
	virtual ~AMateria();

	string	const & getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

};

#endif

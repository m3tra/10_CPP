/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:31:04 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:15:28 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Thunder.hpp"
#include "Barrier.hpp"

using std::string;

class MateriaSource : public IMateriaSource {

private:

	AMateria*	_known[4];
	size_t		_nKnown;

public:

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator = (const MateriaSource& other);
	virtual ~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria*	createMateria(string const & type);

};

#endif

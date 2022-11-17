/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Barrier.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:14:35 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BARRIER_HPP
#define BARRIER_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;

class Barrier : public AMateria {

public:

	Barrier();
	Barrier(const Barrier& other);
	Barrier& operator = (const Barrier& other);
	virtual ~Barrier();

	void		use(ICharacter& target);
	Barrier*	clone() const;

};

#endif

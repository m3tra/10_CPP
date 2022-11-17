/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 12:15:09 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure& other);
	Cure& operator = (const Cure& other);
	virtual ~Cure();

	void	use(ICharacter& target);
	Cure*	clone() const;

};

#endif

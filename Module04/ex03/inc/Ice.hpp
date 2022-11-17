/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 12:15:07 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;

class Ice : public AMateria {

public:

	Ice();
	Ice(const Ice& other);
	Ice& operator = (const Ice& other);
	virtual ~Ice();

	void	use(ICharacter& target);
	Ice*	clone() const;

};

#endif

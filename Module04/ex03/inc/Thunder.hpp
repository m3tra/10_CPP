/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:14:06 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUNDER_HPP
#define THUNDER_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;

class Thunder : public AMateria {

public:

	Thunder();
	Thunder(const Thunder& other);
	Thunder& operator = (const Thunder& other);
	virtual ~Thunder();

	void		use(ICharacter& target);
	Thunder*	clone() const;

};

#endif

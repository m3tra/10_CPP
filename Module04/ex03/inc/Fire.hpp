/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:14:10 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;

class Fire : public AMateria {

public:

	Fire();
	Fire(const Fire& other);
	Fire& operator = (const Fire& other);
	virtual ~Fire();

	void	use(ICharacter& target);
	Fire*	clone() const;

};

#endif

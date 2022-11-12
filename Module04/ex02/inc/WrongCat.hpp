/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/10/31 05:58:42 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

using std::string;

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator = (const WrongCat& other);
	~WrongCat();

	void	makeSound() const;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/11 05:33:51 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

using std::string;

class Dog : public Animal {

private:

	Brain*	_brain;

public:

	Dog();
	Dog(const Dog& other);
	Dog& operator = (const Dog& other);
	~Dog();

	void	makeSound() const;
	void	eureka(const string& idea);
	void	amnesia(const string& idea);
	void	listIdeas();

};

#endif

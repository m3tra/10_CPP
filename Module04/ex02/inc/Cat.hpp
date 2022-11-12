/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/11 05:57:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

using std::string;

class Cat : public Animal {

private:

	Brain*	_brain;

public:

	Cat();
	Cat(const Cat& other);
	Cat& operator = (const Cat& other);
	~Cat();

	void	makeSound() const;
	void	eureka(const string& idea);
	void	amnesia(const string& idea);
	void	listIdeas();

};

#endif

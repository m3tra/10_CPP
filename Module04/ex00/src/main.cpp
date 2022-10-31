/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:58:09 by fporto            #+#    #+#             */
/*   Updated: 2022/10/31 07:46:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	given_tests() {
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
}

static void	wrong_tests() {
	const	WrongAnimal* meta = new WrongAnimal();
	const	WrongAnimal* i = new WrongCat();

	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
}

int	main() {
	given_tests();

	std::cout << std::endl;

	wrong_tests();

	return (0);
}

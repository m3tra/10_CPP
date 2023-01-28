/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:58:09 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 12:54:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	given_tests() {
	const	Animal* meta = new Animal();
	std::cout << std::endl;
	const	Animal* j = new Dog();
	std::cout << std::endl;
	const	Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
}

static void	wrong_tests() {
	const	WrongAnimal* meta = new WrongAnimal();
	std::cout << std::endl;
	const	WrongAnimal* i = new WrongCat();
	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete i;
}

int	main() {
	given_tests();

	std::cout << RED << "WRONG CLASS" << WHITE << std::endl;

	wrong_tests();

	return (0);
}

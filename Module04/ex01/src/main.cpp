/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:58:09 by fporto            #+#    #+#             */
/*   Updated: 2022/11/01 06:28:01 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// static void	other_tests() {
// 	const	WrongAnimal* meta = new WrongAnimal();
// 	const	WrongAnimal* i = new WrongCat();

// 	std::cout << std::endl;

// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	meta->makeSound();

// 	std::cout << std::endl;

// 	delete meta;
// 	delete i;
// }

int	main() {
	const Animal*	j = new Dog();
	std::cout << std::endl;
	const Animal*	i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << std::endl;

	Animal*	arr[6];

	for (size_t it = 0; it < 3; it++) {
		arr[it] = new Dog();
	}
	std::cout << std::endl;
	for (size_t it = 3; it < 6; it++) {
		arr[it] = new Cat();
	}

	std::cout << std::endl;

	for (size_t it = 0; it < 6; it++) {
		delete arr[it];
	}

	// for (size_t it = 0; it < 3; it++) {
	// 	delete static_cast<Dog*>(arr[it]);
	// }
	// std::cout << std::endl;
	// for (size_t it = 3; it < 6; it++) {
	// 	delete static_cast<Cat*>(arr[it]);
	// }

	// other_tests();

	return (0);
}

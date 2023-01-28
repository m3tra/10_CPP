/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:58:09 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 13:41:54 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	givenTests() {
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;
}

void	dogTests(AAnimal* arr[], const size_t arrSize) {
	std::cout << YELLOW << "Last dog" << WHITE << "'s ideas:" << std::endl;
	static_cast<Dog*>(arr[arrSize / 2 - 1])->eureka("Want lasagna");
	static_cast<Dog*>(arr[arrSize / 2 - 1])->eureka("Need coffee");
	static_cast<Dog*>(arr[arrSize / 2 - 1])->eureka("Love sleep");
	static_cast<Dog*>(arr[arrSize / 2 - 1])->listIdeas();
	std::cout << std::endl;

	Dog	odie;
	std::cout << YELLOW << "CopyDog" << WHITE << "'s ideas before copy: " << std::endl;
	std::cout << std::endl;
	odie = *static_cast<Dog*>(arr[0]);
	std::cout << YELLOW << "CopyDog" << WHITE << "'s ideas after copy: " << std::endl;
	odie.listIdeas();
	std::cout << std::endl;
}

void	catTests(AAnimal* arr[], const size_t arrSize) {
	std::cout << YELLOW << "Last cat" << WHITE << "'s ideas:" << std::endl;
	static_cast<Cat*>(arr[arrSize - 1])->eureka("Want lasagna");
	static_cast<Cat*>(arr[arrSize - 1])->eureka("Need coffee");
	static_cast<Cat*>(arr[arrSize - 1])->eureka("Love sleep");
	static_cast<Cat*>(arr[arrSize - 1])->listIdeas();
	std::cout << std::endl;

	Cat	garfield;
	std::cout << YELLOW << "CopyCat" << WHITE << "'s ideas before copy: " << std::endl;
	std::cout << std::endl;
	garfield = *static_cast<Cat*>(arr[arrSize - 1]);
	std::cout << YELLOW << "CopyCat" << WHITE << "'s ideas after copy: " << std::endl;
	garfield.listIdeas();
	std::cout << std::endl;
}

int	main() {
	givenTests();

	std::cout << ORANGE << "CUSTOM TESTS" << WHITE << std::endl;

	const size_t	arrSize = 4;
	AAnimal*			arr[arrSize];
	size_t			it;

	for (it = 0; it < arrSize / 2; it++) {
		arr[it] = new Dog();
		static_cast<Dog*>(arr[it])->eureka("Gett boane");
	}
	std::cout << std::endl;
	for (; it < arrSize; it++) {
		arr[it] = new Cat();
		static_cast<Cat*>(arr[it])->eureka("Who let the dogs out?");
	}

	std::cout << ORANGE << "CAT TESTS" << WHITE << std::endl;
	catTests(arr, arrSize);
	std::cout << ORANGE << "DOG TESTS" << WHITE << std::endl;
	dogTests(arr, arrSize);

	for (it = 0; it < arrSize; it++)
		delete arr[it];

	// Is instatiable?
	AAnimal*	noAnimal = new AAnimal();
	delete noAnimal;

	return (0);
}

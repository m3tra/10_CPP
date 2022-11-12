/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:58:09 by fporto            #+#    #+#             */
/*   Updated: 2022/11/12 06:48:49 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal*	j = new Dog();
	std::cout << std::endl;
	const Animal*	i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << std::endl;

	const size_t	arrSize = 6;
	Animal*			arr[arrSize];
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
	std::cout << std::endl;

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

	for (it = 0; it < arrSize; it++)
		delete arr[it];

	std::cout << std::endl << "Is instatiable?" << std::endl;
	Animal*	noAnimal = new Animal();
	delete noAnimal;

	std::cout << std::endl;

	return (0);
}

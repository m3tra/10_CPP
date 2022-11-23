/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:29:24 by fporto            #+#    #+#             */
/*   Updated: 2022/11/23 16:36:13 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 7

template<typename T>
void	printArray(T& arr) {
	for (unsigned int i = 0; i < arr.size() ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int		main() {
	std::cout << "MAX_VAL = 7" << std::endl;
	{
		std::cout << PURPLE "Construction without parameter " BLUE "Array<size_t> empty" WHITE << std::endl;
		Array<int> empty;
		std::cout << empty;
		std::cout << GREEN "OK" WHITE << std::endl;
	}
	{
		std::cout << PURPLE "Construction without parameter " BLUE "Array<size_t> empty" WHITE << std::endl;
		Array<size_t> empty;
		std::cout << empty;
		std::cout << GREEN "OK" WHITE << std::endl;
	}

	std::cout << PURPLE "Construction with size parameter " BLUE "Array<int> numbers(MAX_VAL)" WHITE << std::endl;
	Array<int> numbers(MAX_VAL);
	std::cout << numbers;
	std::cout << GREEN "OK" WHITE << std::endl;

	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	std::cout << PURPLE "Filling array with random values " BLUE "Array<int> numbers(MAX_VAL)" WHITE " and " BLUE "int* mirror" WHITE << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		int value = rand() % 1000;
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << BLUE "numbers: \n" << WHITE << numbers;
	std::cout << GREEN "OK" WHITE << std::endl;

	std::cout << PURPLE "Testing for equivalence " BLUE "Array<int> tmp = numbers" WHITE " and " BLUE "int* mirror" WHITE << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << RED "didn't save the same value!!" WHITE << std::endl;
			return 2;
		}
	}
	std::cout << GREEN "OK" WHITE << std::endl;

	//SCOPE
	{
		std::cout << PURPLE "Construction with copy and assignement operator" WHITE << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << GREEN "OK" WHITE << std::endl;

		std::cout << PURPLE "Testing for equivalence " BLUE "Array<int> tmp = numbers" WHITE " and " BLUE "Array<int> test(tmp)" WHITE << std::endl;
		for (int i = 0; i < MAX_VAL; i++) {
			if (test[i] != numbers[i]) {
				std::cerr << RED "didn't save the same value!!" WHITE << std::endl;
				return 1;
			}
		}
		std::cout << GREEN "OK" WHITE << std::endl;
	}

	std::cout << PURPLE "Acess with index out of bounds " WHITE "(suppose to fail)" << std::endl;
	std::cout << "index = -2" << std::endl;
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << WHITE << std::endl;
	}
	std::cout << "index = MAX_VAL" << std::endl;
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << WHITE << std::endl;
	}

	delete [] mirror;

	return 0;
}

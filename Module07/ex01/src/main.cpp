/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:29:24 by fporto            #+#    #+#             */
/*   Updated: 2022/11/22 16:08:49 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	times2(T &elem) {
	elem *= 2;
}

template<typename T, typename F>
void	iter(T *arr , size_t len, F f) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void	printArray(T& arr, size_t len) {
	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main( void ) {
	int		arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t	arr2[7] = {1, 3, 5, 7, 11, 13, 17};

	std::cout << BLUE "Int " WHITE "array" << std::endl;

	std::cout << "Before:" << std::endl;
	printArray(arr, 10);
	::iter(arr, 10, times2<int>);
	std::cout << "After:" << std::endl;
	printArray(arr, 10);


	std::cout << std::endl;
	std::cout << BLUE "Size_t " WHITE "array" << std::endl;

	std::cout << "Before:" << std::endl;
	printArray(arr2, 7);
	::iter(arr2, 7, times2<size_t>);
	std::cout << "After:" << std::endl;
	printArray(arr2, 7);

	return 0;
}

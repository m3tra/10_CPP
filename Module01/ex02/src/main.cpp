/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 05:52:14 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:04:18 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;

int	main() {
	string	str = "HI THIS IS BRAIN";
	string*	strPtr = &str;
	string&	strRef = str;

	std::cout << "str\t mem address: " << &str << std::endl;
	std::cout << "strPtr\t mem address: " << &strPtr << std::endl;
	std::cout << "strRef\t mem address: " << &strRef << std::endl;

	std::cout << "str\t value: " << str << std::endl;
	std::cout << "strPtr\t value: " << strPtr << std::endl;
	std::cout << "strRef\t value: " << strRef << std::endl;
}

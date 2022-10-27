/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 05:52:14 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 07:23:30 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;

int	main() {
	string	str = "HI THIS IS BRAIN";
	string*	strPtr = &str;
	string&	strRef = str;

	std::cout << "str mem address: " << &str << std::endl;
	std::cout << "strPtr mem address: " << &strPtr << std::endl;
	std::cout << "strRef mem address: " << &strRef << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "strPtr value: " << strPtr << std::endl;
	std::cout << "strRef value: " << strRef << std::endl;
}

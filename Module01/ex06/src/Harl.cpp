/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:13 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:49:21 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) {
	std::cout << PURPLE << "[ DEBUG ]" << WHITE << std::endl;
	std::cout << "I love me some boneless pizza with 2L of coke, swear on my *YEEZY*" << std::endl;
}

void	Harl::_info(void) {
	std::cout << BLUE << "[ INFO ]" << WHITE << std::endl;
	std::cout << "2L machine broke, they got 1L tho." << std::endl;
}

void	Harl::_warning(void) {
	std::cout << YELLOW << "[ WARNING ]" << WHITE << std::endl;
	std::cout << "My pizza better not have bones in it breh." << std::endl;
}

void	Harl::_error(void) {
	std::cout << RED << "[ ERROR ]" << WHITE << std::endl;
	std::cout << "This **** got bone in it. Where's your *MANAGER*?" << std::endl;;
}

void	Harl::complain(char* arg) {
	switch (arg[0]) {
		case 'D':
			_debug();
			_info();
			_warning();
			_error();
			break;
		case 'I':
			_info();
			_warning();
			_error();
			break;
		case 'W':
			_warning();
			_error();
			break;
		case 'E':
			_error();
			break;
	}
}

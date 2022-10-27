/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:13 by fporto            #+#    #+#             */
/*   Updated: 2022/08/03 03:54:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) {
	std::cout << "I love me some boneless pizza with 2L of coke, swear on my *YEEZY*" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "2L machine broke, they got 1L tho." << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "There better not be bones in it breh." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This sh!t got bone in it. Where's your *MANAGER*?" << std::endl;;
}

void	Harl::complain(string level) {
	string	array[] = {"debug", "info", "warning", "error"};
	void	(*funcs[])(void) = {_debug, _info, _warning, _error};

	for (int i = 0; i < 4; i++)
		if (array[i] == level)
			funcs[i]();
}

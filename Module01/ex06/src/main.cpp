/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:06:16 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:48:17 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv) {
	Harl	harl;

	if (argc != 2) {
		std::cout << RED << "Wrong number of args" << WHITE << std::endl;
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		std::cout << "<level>: DEBUG, INFO, WARNING or ERROR" << std::endl;
		return (1);
	}

	string	arg = static_cast<string>(argv[1]);
	if (!arg.compare("DEBUG") || !arg.compare("INFO") || !arg.compare("WARNING") || !arg.compare("ERROR"))
		harl.complain(argv[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}

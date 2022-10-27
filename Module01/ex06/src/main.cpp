/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:06:16 by fporto            #+#    #+#             */
/*   Updated: 2022/08/03 04:05:09 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv) {
	Harl	harl;

	if (argc == 2) {
		string	arg = static_cast<string>(argv[1]);
		if (!arg.compare("DEBUG") || !arg.compare("INFO") || !arg.compare("WARNING") || !arg.compare("ERROR")) {
			harl.complain(argv[1]);
			return (0);
		}
	}
	std::cout << "Usage: ./harlFilter <level>" << std::endl;
	std::cout << "<level>: DEBUG, INFO, WARNING or ERROR" << std::endl;
	return (1);
}

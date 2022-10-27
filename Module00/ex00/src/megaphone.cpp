/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:19:37 by fporto            #+#    #+#             */
/*   Updated: 2022/07/31 21:19:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	std::string	tmp;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++) {
		tmp = argv[i];
		for (size_t j = 0; j < tmp.length(); j++)
			std::cout << static_cast<char> (toupper(tmp[j]));
	}
	std::cout << std::endl;

	return (0);
}

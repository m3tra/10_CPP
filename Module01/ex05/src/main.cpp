/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:15 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:42:05 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {
	Harl	harl;

	harl.complain("debug");
	std::cout << std::endl;

	harl.complain("info");
	std::cout << std::endl;

	harl.complain("warning");
	std::cout << std::endl;

	harl.complain("error");
}

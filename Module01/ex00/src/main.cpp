/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:37:13 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 11:33:01 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	randomChump("Gui");
	std::cout << std::endl;
	randomChump("Tó");
	std::cout << std::endl;
	randomChump("Zé");

	return (0);
}

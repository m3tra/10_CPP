/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:37:13 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 05:50:00 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int		N = 2;

	Zombie*	horde = zombieHorde(N, "Gui");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}

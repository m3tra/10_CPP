/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:29:51 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 05:45:44 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, string name) {
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}

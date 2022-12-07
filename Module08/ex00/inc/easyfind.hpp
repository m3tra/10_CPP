/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:47 by fporto            #+#    #+#             */
/*   Updated: 2022/12/07 14:06:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// #include <set>
#include <exception>
#include <vector>

template<typename T>
std::vector<int>::iterator easyfind(T container, int target) {
	// for (int i= 0; i < target; i++)
	// 	if (T[i] == target)
	// 		return T + i;

	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++) {
		if (*it == target)
			return it;
	}

	throw (std::exception());
}

#endif

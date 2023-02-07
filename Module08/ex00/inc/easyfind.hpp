/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:47 by fporto            #+#    #+#             */
/*   Updated: 2023/02/07 04:02:35 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

# include <vector>
# include <deque>
# include <list>

# include <algorithm>

# include "color.hpp"

template<typename T>
bool	easyfind(const T& container, const int target) {
	std::cout << "Item " BLUE << target << " ";

	if (std::find(container.begin(), container.end(), target) == container.end()) {
		std::cout << RED "not found" WHITE << std::endl;
		return false;
	}
	std::cout << GREEN "found" WHITE << std::endl;
	return true;
}

#endif

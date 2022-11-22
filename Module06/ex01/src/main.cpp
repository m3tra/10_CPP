/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:09:53 by fporto            #+#    #+#             */
/*   Updated: 2022/11/22 11:30:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int			main() {
	Data	data;
	data.value = 42;
	data.str = "quarante-deux";

	Data	*conv = deserialize(serialize(&data));

	std::cout << "Original:  " << std::endl;
	std::cout << "    " << data.value << std::endl;
	std::cout << "    " << data.str << std::endl;

	std::cout << "Converted: " << std::endl;
	std::cout << "    " << conv->value << std::endl;
	std::cout << "    " << conv->str << std::endl;

	return 0;
}

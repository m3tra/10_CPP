/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:09:53 by fporto            #+#    #+#             */
/*   Updated: 2023/01/29 17:40:24 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	generate(void) {
	Base*	ret;

	switch (rand() % 3) {
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
			break;
	}
	return ret;
}

void	identify(Base* p) {
	std::cout << "Class of type (*) ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	std::cout << "Class of type (&) ";
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int		main() {
	size_t	amount = 10;

	srand(time(NULL));
	for (size_t i = 0; i < amount; i++) {
		Base	*tmp = generate();
		identify(tmp);
		identify(*tmp);
		std::cout << std::endl;
		delete tmp;
	}

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:53:17 by fporto            #+#    #+#             */
/*   Updated: 2022/11/17 04:02:29 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Thunder.hpp"
#include "Barrier.hpp"

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "list.hpp"

static void	extraTests() {
	IMateriaSource* src = new MateriaSource();

	std::cout << ORANGE "Materia learning test" WHITE << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Thunder());
	src->learnMateria(new Barrier());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << ORANGE "Materia creation test" WHITE << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("thunder");
	me->equip(tmp);
	tmp = src->createMateria("barrier");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << ORANGE "Materia use test" WHITE << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
}

static void	givenCode() {
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
}

int	main() {
	t_list* list = newList();

	std::cout << RED "Given tests" WHITE << std::endl;
	givenCode();

	std::cout << std::endl;

	std::cout << RED "Extra tests" WHITE << std::endl;
	extraTests();

	freeList(list);

	return 0;
}

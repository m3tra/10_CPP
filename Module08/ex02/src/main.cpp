/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:02:02 by fporto            #+#    #+#             */
/*   Updated: 2023/02/07 04:35:47 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	givenTests() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << BLUE "mstack" WHITE " top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << WHITE << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << PURPLE "While loop:" WHITE << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

// #############################################################################
// TEST COPY CONSTRUCTOR
// #############################################################################

	std::cout << std::endl << YELLOW "MutantStack" WHITE;
	std::cout << "<" PURPLE "int" WHITE "> ";
	std::cout << BLUE "mstack2" WHITE "(" BLUE "mstack" WHITE ")" << std::endl;
	MutantStack<int> mstack2(mstack);

	std::cout << "&" BLUE "mstack" WHITE ":  " << &mstack << std::endl;
	std::cout << "&" BLUE "mstack2" WHITE ": " << &mstack2;
	if (&mstack != &mstack2)
		std::cout << GREEN " Different" WHITE << std::endl;
	else
		std::cout << RED "Same" WHITE << std::endl;

	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << PURPLE "While loop:" WHITE << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

// #############################################################################
// TEST COPY ASSIGNMENT OPERATOR
// #############################################################################

	std::cout << std::endl << YELLOW "MutantStack" WHITE;
	std::cout << "<" PURPLE "int" WHITE "> ";
	std::cout << BLUE "mstack3" WHITE " = " BLUE "mstack" WHITE << std::endl;
	MutantStack<int> mstack3 = mstack;

	std::cout << "&" BLUE "mstack" WHITE ":  " << &mstack << std::endl;
	std::cout << "&" BLUE "mstack3" WHITE ": " << &mstack2;
	if (&mstack != &mstack3)
		std::cout << GREEN " Different" WHITE << std::endl;
	else
		std::cout << RED "Same" WHITE << std::endl;

	it = mstack3.begin();
	ite = mstack3.end();
	std::cout << PURPLE "While loop:" WHITE << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

// #############################################################################
// TEST CASTING TO DEFAULT STACK
// #############################################################################

	std::stack<int> s(mstack);

	std::cout << std::endl << YELLOW "std::stack" WHITE;
	std::cout << "<" PURPLE "int" WHITE ">";
	std::cout << BLUE " s" WHITE "(" BLUE "mstack" WHITE ")" << std::endl;
	while(!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

void	listTests() {
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << BLUE "mlist" WHITE " back: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "size: " << mlist.size() << WHITE << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();

	std::cout << PURPLE "While loop:" WHITE << std::endl;

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

// #############################################################################
// TEST COPY CONSTRUCTOR
// #############################################################################

	std::cout << std::endl << YELLOW "std::list" WHITE;
	std::cout << "<" PURPLE "int" WHITE "> ";
	std::cout << BLUE "mlist2" WHITE "(" BLUE "mlist" WHITE ")" << std::endl;
	std::list<int> mlist2(mlist);

	std::cout << "&" BLUE "mlist" WHITE ":  " << &mlist << std::endl;
	std::cout << "&" BLUE "mlist2" WHITE ": " << &mlist2;
	if (&mlist != &mlist2)
		std::cout << GREEN " Different" WHITE << std::endl;
	else
		std::cout << RED "Same" WHITE << std::endl;

	it = mlist2.begin();
	ite = mlist2.end();
	std::cout << PURPLE "While loop:" WHITE << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

// #############################################################################
// TEST COPY ASSIGNMENT OPERATOR
// #############################################################################

	std::cout << std::endl << YELLOW "std::list" WHITE;
	std::cout << "<" PURPLE "int" WHITE "> ";
	std::cout << BLUE "mlist3" WHITE " = " BLUE "mlist" WHITE << std::endl;
	std::list<int> mlist3 = mlist;

	std::cout << "&" BLUE "mlist" WHITE ":  " << &mlist << std::endl;
	std::cout << "&" BLUE "mlist3" WHITE ": " << &mlist2;
	if (&mlist != &mlist3)
		std::cout << GREEN " Different" WHITE << std::endl;
	else
		std::cout << RED "Same" WHITE << std::endl;

	it = mlist3.begin();
	ite = mlist3.end();
	std::cout << PURPLE "While loop:" WHITE << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	std::cout << ORANGE "GIVEN CODE" WHITE << std::endl;
	givenTests();

	std::cout << std::endl << std::endl << std::endl;

	std::cout << ORANGE "LIST VERSION" WHITE << std::endl;
	listTests();

	return 0;
}

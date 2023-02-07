/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:40:58 by fporto            #+#    #+#             */
/*   Updated: 2023/02/07 01:50:42 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vec(other._vec) {}

Span& Span::operator = (const Span& other) {
	this->_maxSize = other._maxSize;
	this->_vec = other._vec;
	return *this;
}

Span::~Span() {}



const char* Span::AddException::what() const throw() {
	return "Cannot add. Span already full";
}

const char* Span::SpanException::what() const throw() {
	return "Less than 2 items stored";
}



void	Span::addNumber(int n) throw (AddException) {
	if (this->_vec.size() == _maxSize)
		throw AddException();

	this->_vec.push_back(n);
}

int		Span::shortestSpan() throw (SpanException) {
	int							span = 0;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;

	if (_vec.size() < 2)
		throw SpanException();

	for (it = _vec.begin(); it != _vec.end(); it++) {
		for (it2 = it; ++it2 != _vec.end();) {
			int	tmp = abs(*it - *it2);
			if (it == _vec.begin())
				span = tmp;

			if (span > tmp)
				span = tmp;
		}
	}
	return span;
}

int		Span::longestSpan() throw (SpanException) {
	int							span = 0;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;

	if (_vec.size() < 2)
		throw SpanException();

	for (it = _vec.begin(); it != _vec.end(); it++) {
		for (it2 = it; ++it2 != _vec.end();) {
			int	tmp = abs(*it - *it2);

			if (it == _vec.begin())
				span = tmp;

			if (span < tmp)
				span = tmp;
		}
	}
	return span;
}

void	Span::addRange(std::vector<int>::iterator first,
						std::vector<int>::iterator last) {
	std::vector<int>::iterator end = this->_vec.end();
	this->_vec.insert(end, first, last);
}


// Hardcoded insertion at end of Span
void	Span::printArray() {
	for (std::vector<int>::iterator it = this->_vec.begin();
		it != this->_vec.end();
		it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:40:58 by fporto            #+#    #+#             */
/*   Updated: 2023/02/06 19:56:20 by fporto           ###   ########.fr       */
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

int	Span::shortestSpan() throw (SpanException) {
	int							span = 0;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;

	if (_vec.size() < 2)
		throw SpanException();

	for (it = _vec.begin(); it != _vec.end(); it++) {
		for (it2 = it; ++it2 != _vec.end();) {
			if (it == _vec.begin())
				span = abs(*it - *it2);

			if (span > abs(*it - *it2))
				span = abs(*it - *it2);
		}
	}
	return span;
}

int	Span::longestSpan() throw (SpanException) {
	int							span = 0;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;

	if (_vec.size() < 2)
		throw SpanException();

	for (it = _vec.begin(); it != _vec.end(); it++) {
		for (it2 = it; ++it2 != _vec.end();) {
			if (it == _vec.begin())
				span = abs(*it - *it2);

			if (span < abs(*it - *it2))
				span = abs(*it - *it2);
		}
	}
	return span;
}

void	addRange(std::vector<int> &vec, std::vector<int>::iterator pos, std::vector<int>::iterator first, std::vector<int>::iterator last) {
	vec.insert(pos, first, last);
}

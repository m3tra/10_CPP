/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:40:58 by fporto            #+#    #+#             */
/*   Updated: 2023/02/01 22:33:12 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t N) : _maxsize(N) {}

Span::Span(const Span& other) {
	_vec = other;
}

Span& Span::operator = (const Span& other) {
	_vec = other;
}

Span::~Span() {}



void	Span::addNumber(int n) {
	if (_vec.size() == _maxSize)
		throw std::exception();

	_vec.push_back();
}

size_t	Span::shortestSpan() {
	size_t						span = 0;
	std::vector<int>::iterator	it;

	for (it = _vec.begin(); it != _vec.end(); it++) {
		if (!span)

	}

}

size_t	Span::longestSpan() {

}

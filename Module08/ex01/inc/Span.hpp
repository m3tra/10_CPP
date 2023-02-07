/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:37:39 by fporto            #+#    #+#             */
/*   Updated: 2023/02/07 04:02:26 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <ctime>

# include <vector>
# include <deque>
# include <list>

# include <algorithm>

# include "color.hpp"

class	Span {
private:
	size_t	_maxSize;
	std::vector<int> _vec;

public:
	Span(size_t	N);
	Span(const Span& other);
	Span& operator = (const Span& other);
	~Span();

	class AddException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	class SpanException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	void	addNumber(int n) throw (AddException);
	int		shortestSpan() throw (SpanException);
	int		longestSpan() throw (SpanException);

	void	addRange(std::vector<int>::iterator first, \
					std::vector<int>::iterator last);

	void	printArray();
};

#endif

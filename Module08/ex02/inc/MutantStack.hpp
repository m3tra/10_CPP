/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:32:49 by fporto            #+#    #+#             */
/*   Updated: 2023/02/07 04:02:19 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "color.hpp"

# include <iostream>

# include <deque>
# include <stack>
# include <iterator>

# include <list>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &stack) {
			*this = stack;
		}
		~MutantStack() {}

		typedef typename Container::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif

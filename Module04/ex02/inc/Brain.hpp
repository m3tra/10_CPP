/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/11 05:57:41 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

using std::string;

class Brain {

public:

	string	ideas[100];

	Brain();
	Brain(const Brain& other);
	Brain& operator = (const Brain& other);
	~Brain();

	void	eureka(const string& idea);
	void	amnesia(const string& idea);
	void	listIdeas();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:00:48 by fporto            #+#    #+#             */
/*   Updated: 2022/11/22 12:15:05 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

using std::string;

class Base {
	public:

		virtual ~Base() {};

};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif

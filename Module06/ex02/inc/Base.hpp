/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:00:48 by fporto            #+#    #+#             */
/*   Updated: 2023/01/29 17:40:12 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;

class Base {
	public:

		virtual ~Base() {};

};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif

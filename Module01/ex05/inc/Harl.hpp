/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:25 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:37:21 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

using std::string;

class	Harl {

private:

	static void	_debug(void);
	static void	_info(void);
	static void	_warning(void);
	static void	_error(void);

public:

	void	complain(string level);

};

#endif

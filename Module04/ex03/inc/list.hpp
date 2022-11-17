/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:12:52 by fporto            #+#    #+#             */
/*   Updated: 2022/11/15 12:29:13 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "AMateria.hpp"

typedef struct s_listElem {
	AMateria*	materia;
	struct s_listElem* next;
}	t_listElem;

typedef struct s_list {
	t_listElem*	top;
	size_t		size;
}	t_list;



t_list*	newList();
void	freeList(t_list* list);
void	addToList(t_list* list, AMateria* materia);
t_list*	listDup(t_list* src);

#endif

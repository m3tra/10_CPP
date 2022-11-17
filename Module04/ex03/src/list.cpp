/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:40:44 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 01:41:22 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

t_list*	newList() {
	t_list*	list = new t_list;

	list->top = NULL;
	list->size = 0;

	return list;
}

void	freeList(t_list* list) {
	t_listElem*	tmpElem;

	while (list->size) {
		tmpElem = list->top;
		for (size_t i = list->size - 2; i > 0; i--)
			tmpElem = tmpElem->next;
		delete tmpElem;
		list->size--;
	}
	delete list;
}

static t_listElem*	listLast(t_list* list) {
	if (!list->size)
		return NULL;

	t_listElem*	ret = list->top;

	while (ret->next)
		ret = ret->next;
	return ret;
}

void	addToList(t_list* list, AMateria* materia) {
	t_listElem*	lastElem = listLast(list);
	t_listElem*	newElem = new t_listElem;

	newElem->materia = materia;
	newElem->next = NULL;
	if (!lastElem)
		list->top = newElem;
	else
		lastElem->next = newElem;
	list->size++;
}

t_list*	listDup(t_list* src) {
	t_list*		ret = new t_list;
	ret->top = NULL;
	ret->size = src->size;

	if (!ret->size)
		return ret;

	t_listElem*	tmp = src->top;

	while (tmp->next) {
		addToList(ret, tmp->materia);
		tmp = tmp->next;
	}
	addToList(ret, tmp->materia);

	return ret;
}

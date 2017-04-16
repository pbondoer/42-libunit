/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:10:08 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/11 15:25:12 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

/*
** Appends a list element created with list_new to the end of list.
** Needed to ensure tests are run in the order they are called.
** We do not check for NULL as we have done so previously. DRY!
*/

static inline void			list_append(t_unit_list *list, t_unit_list *new)
{
	while (list->next)
		list = list->next;
	list->next = new;
}

/*
** Creates a new list element, duplicating the name string.
** Returns a pointer to the element, or NULL if memory allocation failed.
*/

static inline t_unit_list	*list_new(char *name, t_unit_suite *suite)
{
	t_unit_list		*list;

	if ((list = (t_unit_list *)ft_memalloc(sizeof(t_unit_list))) == NULL)
		return (NULL);
	list->name = name;
	list->suite = suite;
	list->next = NULL;
	return (list);
}

/*
** Adds a suite to a list. If the list is empty, it creates a list.
** Returns a pointer to the element that was created, or NULL if it failed.
*/

t_unit_list					*unit_add_suite(t_unit_list **list, char *name,
								t_unit_suite *suite)
{
	t_unit_list		*new;

	if (list == NULL)
		return (NULL);
	new = list_new(name, suite);
	if (*list == NULL)
		*list = new;
	else
		list_append(*list, new);
	return (new);
}

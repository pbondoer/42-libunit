/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:10:08 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 22:43:35 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

/*
** Appends a suite element created with suite_new to the end of suite.
** Needed to ensure tests are run in the order they are called.
** We do not check for NULL as we have done so previously. DRY!
*/

static inline void			suite_append(t_unit_suite *suite, t_unit_suite *new)
{
	while (suite->next)
		suite = suite->next;
	suite->next = new;
}

/*
** Creates a new suite element, duplicating the name string.
** Returns a pointer to the elemnt, or NULL if memory allocation failed.
*/

static inline t_unit_suite	*suite_new(char *name, t_test test, int expected,
								int use_stdout)
{
	t_unit_suite		*suite;

	if ((suite = (t_unit_suite *)ft_memalloc(sizeof(t_unit_suite))) == NULL)
		return (NULL);
	suite->name = name;
	suite->test = test;
	suite->expected = expected;
	suite->use_stdout = use_stdout;
	suite->next = NULL;
	return (suite);
}

/*
** Adds a single test to a suite. If the suite is empty, it creates a suite.
** Returns a pointer to the element that was created, or NULL if it failed.
*/

t_unit_suite				*unit_add_test(t_unit_suite **suite, char *name,
								t_test_simple test, int expected)
{
	t_unit_suite		*new;

	if (suite == NULL)
		return (NULL);
	new = suite_new(name, (t_test){.simple = test}, expected, 0);
	if (*suite == NULL)
		*suite = new;
	else
		suite_append(*suite, new);
	return (new);
}

/*
** Same as previous function, but defines a test case that catches stdout.
*/

t_unit_suite				*unit_add_test_output(t_unit_suite **suite,
								char *name, t_test_out test, int expected)
{
	t_unit_suite		*new;

	if (suite == NULL)
		return (NULL);
	new = suite_new(name, (t_test){.out = test}, expected, 1);
	if (*suite == NULL)
		*suite = new;
	else
		suite_append(*suite, new);
	return (new);
}

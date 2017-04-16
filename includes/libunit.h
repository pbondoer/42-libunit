/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 07:27:36 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 22:43:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stddef.h>
# include <stdarg.h>

# define TEST_SUCCESS 0
# define TEST_ERROR -1
# define TEST_TIMEOUT 10

typedef int						(*t_test_out)(int *);
typedef int						(*t_test_simple)(void);
typedef struct s_unit_suite		t_unit_suite;
typedef struct s_unit_list		t_unit_list;

typedef union	u_test
{
	t_test_out		out;
	t_test_simple	simple;
}				t_test;

/*
** A test suite contains individual test cases.
** There is generally one test suite per function.
*/

struct			s_unit_suite
{
	char			*name;
	t_test			test;
	int				expected;
	int				use_stdout;
	t_unit_suite	*next;
};

t_unit_suite	*unit_add_test(t_unit_suite **suite, char *name,
					t_test_simple test, int expected);
t_unit_suite	*unit_add_test_output(t_unit_suite **suite, char *name,
					t_test_out test, int expected);
void			unit_run_suite(t_unit_suite *suite, char *name,
					int *count, int *success);
int				unit_assert_output(int *p, char *expect);

/*
** A suite list contains test suites.
** There are as many suites as needed.
*/

struct			s_unit_list
{
	char			*name;
	t_unit_suite	*suite;
	t_unit_list		*next;
};

t_unit_list		*unit_add_suite(t_unit_list **list, char *name,
					t_unit_suite *suite);
int				unit_run_all(t_unit_list *list, char *name);

/*
** Utility functions
*/

void			unit_printf(const char *format, ...);
#endif

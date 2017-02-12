/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 09:52:04 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 22:35:45 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "101_basic_tests.h"
#include "libunit.h"
#include <signal.h>

t_unit_suite		*test_launcher(void)
{
	static t_unit_suite *suite = NULL;

	if (suite)
		return (suite);
	unit_add_test(&suite, "OK test", &test_ok, 0);
	//unit_add_test(&suite, "abort test", &test_abort, 0);
	unit_add_test_output(&suite, "putchar test", &test_putchar, 0);
	unit_add_test(&suite, "Bus error test", &test_buse, SIGBUS);
	return (suite);
}

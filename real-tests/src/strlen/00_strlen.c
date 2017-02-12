/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 09:52:04 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 22:35:06 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "101_basic_tests.h"
#include "libunit.h"
#include <signal.h>

t_unit_suite		*strlen_launcher(void)
{
	static t_unit_suite *suite = NULL;

	if (suite)
		return (suite);
	unit_add_test(&suite, "Basic test", &strlen_basic, 0);
	unit_add_test(&suite, "0 in string test", &strlen_zero, 0);
	unit_add_test(&suite, "NULL test", &strlen_null, SIGSEGV);
	return (suite);
}

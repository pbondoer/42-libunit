/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 09:58:55 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/11 16:03:21 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "101_basic_tests.h"

int		main(int argc, char **argv)
{
	static t_unit_list *list = NULL;

	(void)argc;
	unit_add_suite(&list, "strlen", strlen_launcher());
	unit_add_suite(&list, "test", test_launcher());
	return (unit_run_all(list, argv[0]));
}

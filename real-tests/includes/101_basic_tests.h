/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   101_basic_tests.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:00:18 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:56:40 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_TESTS_H
# define BASIC_TESTS_H

# include "libunit.h"

/*
** strlen tests
*/

t_unit_suite	*strlen_launcher(void);
int				strlen_basic(void);
int				strlen_zero(void);
int				strlen_null(void);

/*
** test tests
*/

t_unit_suite	*test_launcher(void);
int				test_ok(void);
int				test_timeout(void);
int				test_abort(void);
int				test_putchar(int *p);
int				test_buse(void);

#endif

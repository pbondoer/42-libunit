/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:23:29 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:33:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"
#include <unistd.h>

/*
** Reads stdout from a pipe, and returns a value to be used by tests.
*/

int			unit_assert_output(int *p, char *expect)
{
	char	*output;
	size_t	len;
	size_t	actual;
	int		res;

	len = ft_strlen(expect);
	if ((output = ft_strnew(len)) == NULL)
		return (-1);
	actual = read(p[0], output, len + 1);
	if (actual != len)
		res = -1;
	else
		res = (ft_strcmp(expect, output) == 0 ? 0 : -1);
	ft_strdel(&output);
	return (res);
}

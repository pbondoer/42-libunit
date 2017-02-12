/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 09:56:17 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:40:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		strlen_zero(void)
{
	static char *test = "\0I'm a secret string, shh!";

	if (ft_strlen(test) == strlen(test))
		return (0);
	else
		return (-1);
}

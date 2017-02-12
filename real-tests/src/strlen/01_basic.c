/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 09:56:17 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:40:04 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		strlen_basic(void)
{
	static char *test = "Hello, world!";

	if (ft_strlen(test) == strlen(test))
		return (0);
	else
		return (-1);
}

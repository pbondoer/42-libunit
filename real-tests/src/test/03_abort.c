/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:28:46 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:40:50 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		test_abort(void)
{
	void *hello;

	hello = ft_memalloc(1);
	free(hello);
	free(hello);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:15:44 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 21:34:45 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int			test_putchar(int *p)
{
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	return (unit_assert_output(p, "abc"));
}

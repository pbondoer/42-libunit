/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:24 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 23:34:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

/*
** Utility function to write to stdout and a file at the same time.
*/

static void		pf_write(char *str, int len, int fd, int free_str)
{
	if (!str || !*str)
		return ;
	if (len == -1)
		len = ft_strlen(str);
	write(STDIN_FILENO, str, len);
	if (fd != -1)
		write(fd, str, len);
	if (free_str)
		ft_strdel(&str);
}

/*
** Tiny printf function that replaces %s with supplied arguments
*/

void			unit_printf(const char *format, ...)
{
	size_t		len;
	char		*next;
	va_list		ap;
	static int	fd = -2;

	if (fd == -2)
		fd = open("test_results.log", O_WRONLY | O_APPEND | O_CREAT);
	va_start(ap, format);
	while ((next = ft_strstr(format, "%")))
	{
		pf_write((char *)format, (len = (size_t)(next - format)), fd, 0);
		format += len + 1;
		if (*format == 's')
			pf_write(va_arg(ap, char *), -1, fd, 0);
		else if (*format == 'd')
			pf_write(ft_itoa(va_arg(ap, int)), -1, fd, 1);
		else
		{
			pf_write("%", 1, fd, 0);
			continue;
		}
		format++;
	}
	va_end(ap);
	pf_write((char *)format, -1, fd, 0);
}

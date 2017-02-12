/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 08:45:51 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/12 23:35:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libunit.h"
#include "libft.h"
#include "color.h"

/*
** Signal handling, displays appropriate code.
*/

static inline void	display_signal(int status, int *success, int expected)
{
	int		i;
	char	*msg;

	i = WTERMSIG(status);
	if (i == SIGALRM)
	{
		unit_printf(COLOR_CYAN "TIMEOUT\n");
		return ;
	}
	else if (i == SIGSEGV)
		msg = "SEGV";
	else if (i == SIGBUS)
		msg = "BUSE";
	else if (i == SIGABRT)
		msg = "ABRT";
	else
	{
		unit_printf(COLOR_YELLOW "(signal)\n");
		return ;
	}
	if (i == expected)
		(*success)++;
	unit_printf("%s %s\n", (i == expected ? COLOR_GREEN : COLOR_RED), msg);
}

/*
** Waits and displays the appropriate status. ALRM signals are considered
** timeouts.
*/

static inline void	display_status(int *success, int expected)
{
	int			status;
	int			ex;

	wait(&status);
	if (WIFEXITED(status))
	{
		ex = WEXITSTATUS(status);
		if (ex == expected)
		{
			(*success)++;
			unit_printf(COLOR_GREEN "OK\n");
		}
		else
			unit_printf(COLOR_RED "KO\n");
	}
	else if (WIFSIGNALED(status))
		display_signal(status, success, expected);
	else
		unit_printf(COLOR_YELLOW "(error)\n");
}

/*
** Runs a single test and displays the result.
*/

static void			single_test(t_unit_suite *suite, int *success, int out)
{
	int		p[2];
	pid_t	pid;

	unit_printf(COLOR_DEFAULT " > %s: ", suite->name);
	if ((pid = fork()) == -1)
		unit_printf(COLOR_YELLOW "(fork error)\n");
	if (suite->use_stdout && pipe(p) == -1)
		unit_printf(COLOR_YELLOW "(pipe error)\n");
	else if (pid == 0)
	{
		if (suite->use_stdout)
			dup2(p[1], 1);
		alarm(TEST_TIMEOUT);
		exit((suite->use_stdout ? suite->test.out(p) : suite->test.simple()));
	}
	else
		display_status(success, suite->expected);
	if (suite->use_stdout)
	{
		close(p[0]);
		close(p[1]);
		dup2(out, 1);
	}
}

/*
** Runs a test-suite and displays the results.
*/

void				unit_run_suite(t_unit_suite *suite, char *name,
						int *count, int *success)
{
	int				out;
	t_unit_suite	*temp;

	unit_printf(COLOR_BLUE "%s\n", name);
	out = dup(1);
	while ((temp = suite))
	{
		single_test(suite, success, out);
		suite = suite->next;
		ft_memdel((void **)&temp);
		(*count)++;
	}
	close(out);
	unit_printf(COLOR_DEFAULT "\n");
}

/*
** Runs all test suites added to the tests and displays.
*/

int					unit_run_all(t_unit_list *list, char *name)
{
	int			count;
	int			success;
	t_unit_list	*temp;

	count = 0;
	success = 0;
	unit_printf(COLOR_MAGENTA "--- %s ---\n\n", name);
	while ((temp = list))
	{
		unit_run_suite(list->suite, list->name, &count, &success);
		list = list->next;
		ft_memdel((void **)&temp);
	}
	unit_printf("%s%d / %d test passed%s\n\n" COLOR_MAGENTA "--- %s ---\n"
		COLOR_DEFAULT, (success == count ? COLOR_GREEN : COLOR_RED), success,
		count, (success == count ? " 🎉" : ""), name);
	return (success == count ? 0 : -1);
}

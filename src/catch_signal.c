/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:52:51 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:02:51 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include "toolkit.h"
#include <sys/ioctl.h>

static void	handle_other(int sig)
{
	t_all *global;

	(void)sig;
	global = return_global(NULL);
	clean_exit(global);
}

static void	handle_sigstop(int sig)
{
	cc_t	st_buf[2];
	t_all	*global;

	(void)sig;
	global = return_global(NULL);
	*st_buf = global->term.c_cc[VSUSP];
	signal(SIGTSTP, SIG_DFL);
	rst_termios(global);
	ioctl(global->fd, TIOCSTI, st_buf);
}

static void	handle_sigcont(int sig)
{
	t_all *global;

	(void)sig;
	global = return_global(NULL);
	init_termios(global);
	render_items(global);
	signal(SIGTSTP, handle_sigstop);
}

static void	handle_sigwinch(int sig)
{
	t_all *global;

	(void)sig;
	global = return_global(NULL);
	ioctl(global->fd, TIOCGWINSZ, &(global)->ws);
	render_items(global);
}

void		init_signal_handling(void)
{
	int		i;

	signal(SIGTSTP, handle_sigstop);
	signal(SIGCONT, handle_sigcont);
	signal(SIGWINCH, handle_sigwinch);
	i = 1;
	while (i <= 31)
	{
		if (i != SIGTSTP && i != SIGCONT && i != SIGWINCH)
			signal(i, handle_other);
		i++;
	}
}

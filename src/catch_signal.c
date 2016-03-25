/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:52:51 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/25 20:03:02 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include "toolkit.h"
#include <sys/ioctl.h>

void	handle_sigabrt(int sig)
{
	(void)sig;
	t_all *global;

	global = return_global(NULL);
	clean_exit(global);
}

void	handle_sigint(int sig)
{
	(void)sig;
	t_all *global;

	global = return_global(NULL);
	clean_exit(global);
}

void	handle_sigsegv(int sig)
{
	(void)sig;
	t_all *global;

	global = return_global(NULL);
	clean_exit(global);
}

void	handle_sigstop(int sig)
{
	(void)sig;
	char st_buf[2];
	t_all *global;

	global = return_global(NULL);
	st_buf[0] = global->term.c_cc[VSUSP];
	st_buf[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	rst_termios(global);
	ioctl(0, TIOCSTI, st_buf);
	T_PRINT("SIGTSTP\n");
}

void	init_signal_handling(void)
{
	signal(SIGSEGV, handle_sigsegv);
	signal(SIGABRT, handle_sigabrt);
	signal(SIGINT, handle_sigint);
	signal(SIGTSTP, handle_sigstop);
}

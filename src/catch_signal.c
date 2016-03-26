/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:52:51 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/26 19:19:11 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include "toolkit.h"
#include <sys/ioctl.h>
#include <stdio.h>

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
	cc_t st_buf[2];
	t_all *global;

	global = return_global(NULL);
	*st_buf = global->term.c_cc[VSUSP];
	signal(SIGTSTP, SIG_DFL);
	rst_termios(global);
	ioctl(0, TIOCSTI, st_buf);
}

void	handle_sigcont(int sig)
{
	(void)sig;
	t_all *global;

	global = return_global(NULL);
	init_termios(global);
	render_items(global);
	signal(SIGTSTP, handle_sigstop);
}

void	handle_sigwinch(int sig)
{
	(void)sig;
	t_all *global;

	global = return_global(NULL);
	ioctl(0, TIOCGWINSZ, &(global)->ws);
	render_items(global);
}

void	init_signal_handling(void)
{
	signal(SIGTSTP, handle_sigstop);
	signal(SIGSEGV, handle_sigsegv);
	signal(SIGABRT, handle_sigabrt);
	signal(SIGINT, handle_sigint);
	signal(SIGCONT, handle_sigcont);
	signal(SIGWINCH, handle_sigwinch);
}

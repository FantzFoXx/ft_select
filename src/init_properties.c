/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_properties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:09 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:04:05 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"
#include "termios.h"
#include <sys/ioctl.h>

int				init_termios(t_all *global)
{
	if (!isatty(STDIN_FILENO))
		return (-1);
	if ((global->fd = open(ttyname(STDIN_FILENO), O_NOCTTY | O_RDWR)) == -1)
		return (-1);
	if (!global->term_name)
	{
		global->term_name = getenv("TERM");
		if (!global->term_name)
			return (-1);
		if (tgetent(NULL, global->term_name) < 1)
			return (-1);
	}
	if ((tcgetattr(global->fd, &(global)->term) == -1)
		|| (tcgetattr(global->fd, &(global)->term_bak) == -1))
		return (-1);
	global->term.c_cc[VMIN] = 1;
	global->term.c_cc[VTIME] = 0;
	global->term.c_lflag &= ~(ICANON);
	global->term.c_lflag &= ~(ECHO);
	ioctl(global->fd, TIOCGWINSZ, &(global)->ws);
	if (tcsetattr(global->fd, 0, &(global)->term) == -1)
		return (-1);
	T_SETMODE("vi");
	T_SETMODE("ti");
	return (0);
}

int				rst_termios(t_all *global)
{
	T_SETMODE("ve");
	T_SETMODE("te");
	tcsetattr(global->fd, 0, &(global)->term_bak);
	return (0);
}

static int		init_items(t_all *global, char **av)
{
	int		i;
	t_item	*new;

	i = 1;
	new = NULL;
	while (av[i])
	{
		new = t_item_new(ft_strdup(av[i]));
		if (!new)
		{
			clean_exit(global);
			return (-1);
		}
		if (av[i][0])
			t_item_push(&(global->items), new);
		i++;
	}
	if (global->items)
		link_loop(global->items);
	return (0);
}

int				init_env(t_all *global, char **av)
{
	if (init_termios(global) == -1)
		return (-1);
	if (init_items(global, av) == -1)
		return (-1);
	T_SETMODE("cl");
	return (0);
}

void			return_items_to_term(t_all *global)
{
	t_item	*items;
	int		alrd_print;

	alrd_print = 0;
	items = global->items;
	while (!items->last)
	{
		if (items->select)
		{
			ft_putstr(items->item_name);
			alrd_print = 1;
		}
		items = items->next;
		if (items->select && alrd_print)
			ft_putchar(' ');
	}
	if (items->select)
		ft_putstr(items->item_name);
}

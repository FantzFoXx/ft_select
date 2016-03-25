/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_properties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:09 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/25 20:03:04 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

int		init_termios(t_all *global)
{
	global->term_name = getenv("TERM");
	if (!global->term_name)
		return (-1);
	tputs("\033[?1049h\033[H", 0, t_putchar);
	tgetent(NULL, global->term_name);
	tcgetattr(0, &(global)->term);
	global->term.c_lflag &= ~(ICANON);
	global->term.c_lflag &= ~(ECHO);
	//global->term.c_lflag &= ~(ISIG);
	tcsetattr(0, 0, &(global)->term);
	T_SETMODE("vi");
	return (0);
}

int		rst_termios(t_all *global)
{
	T_SETMODE("ve");
	tputs("\033[?1049l", 0, t_putchar);
	tcsetattr(0, 0, &(global)->term);
	return (0);
}

int		init_items(t_all *global, char **av)
{
	int		i;
	t_item *new;

	i = 1;
	new = NULL;
	while (av[i])
	{
		new = t_item_new(ft_strdup(av[i]));
		if (!new)
			return (-1);
		t_item_push(&(global->items), new);
		i++;
	}
	if (global->items)
		link_loop(global->items);
	return (0);
}

int		init_env(t_all *global, char **av)
{
	T_SETMODE("cl");
	if (init_termios(global) == -1)
		return (-1);
	if (init_items(global, av) == -1)
		return (-1);
	return (0);
}

void	return_items_to_term(t_all *global)
{
	t_item *items;

	items = global->items;
	while (!items->last)
	{
		if (items->select)
		{
			ft_putstr(items->item_name);
			ft_putchar(' ');
		}
		items = items->next;
	}
	if (items->select)
	{
		ft_putstr(items->item_name);
		ft_putchar(' ');
	}
}

void	selection_finished(t_all *global)
{
	if (global->items)
		return_items_to_term(global);
	clean_exit(global);
}

void	clean_exit(t_all *global)
{
	rst_termios(global);
	exit(0);
}

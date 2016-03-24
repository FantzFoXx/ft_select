/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_properties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:09 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:34 by udelorme         ###   ########.fr       */
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
	if (init_termios(global) == -1)
		return (-1);
	if (init_items(global, av) == -1)
		return (-1);
	return (0);
}

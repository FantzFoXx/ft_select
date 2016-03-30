/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:12 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:06:55 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"
#include "toolkit.h"
#include <unistd.h>
#include <sys/ioctl.h>

static int		main_loop(t_all *global)
{
	char *buf[5];

	render_items(global);
	while (1)
	{
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if ((int)*buf == 27)
			return (0);
		if (global->is_printable)
		{
			handle_key(global, (int)*buf);
			render_items(global);
		}
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_all *global;

	if (argc < 2)
		return (1);
	init_signal_handling();
	global = t_all_new();
	return_global(global);
	if (init_env(global, argv) == 0)
		main_loop(global);
	else
		return (-1);
	clean_exit(global);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:12 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"
#include "toolkit.h"
#include <unistd.h>

int		main_loop(t_all *global)
{
	(void)global;
	char *buf[5];
	
	while (1)
	{
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if ((int)*buf == 27)
			return (0);
		handle_key(global, (int)*buf);
		//ft_putnbr((int)*buf);
	}
	return (0);
}

int		main(int argc, char **argv, char **environ)
{
	(void)environ;
	t_all *global;
	char *res;

	if (argc < 2)
		return (1);
	global = t_all_new();
	init_env(global, argv);

	res = tgetstr("cl", NULL);
	tputs(res, 0, t_putchar);

	render_items(global);
	main_loop(global);
	//sleep(5);
	rst_termios(global);
	ft_putendl("/");
	return (0);
}

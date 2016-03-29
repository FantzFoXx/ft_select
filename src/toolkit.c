/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:17:58 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/29 19:44:20 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

int		t_putchar(int c)
{
	static t_all *global = NULL;

	if (!global)
		global = return_global(NULL);
	if (global)
		write(global->fd, &c, 1);
	return (1);
}

void	clear_term(t_all *global)
{
	T_SETMODE("cl");
}

t_all	*return_global(t_all *global)
{
	static t_all *global_ptr = NULL;

	if (global)
		global_ptr = global;
	return (global_ptr);
}

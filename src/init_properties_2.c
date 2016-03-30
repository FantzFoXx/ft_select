/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_properties_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:43:07 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:05:23 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

static void	free_items(t_all *global)
{
	while (global->items)
		item_delete(global, global->items);
}

void		selection_finished(t_all *global)
{
	rst_termios(global);
	if (global->items)
		return_items_to_term(global);
	free_items(global);
	close(global->fd);
	free(global);
	exit(0);
}

void		clean_exit(t_all *global)
{
	rst_termios(global);
	close(global->fd);
	exit(0);
}

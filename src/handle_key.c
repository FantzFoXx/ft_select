/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:11:58 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:00:49 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "toolkit.h"

static void	move_index_up(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->prev;
	index->ind = 0;
	index->prev->ind = 1;
}

static void	move_index_down(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	index->ind = 0;
	index->next->ind = 1;
}

static void	select_item(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	if (!index->select)
		index->select = 1;
	else
		index->select = 0;
	move_index_down(global);
}

static void	delete_item(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	if (item_delete(global, index) == 0)
		clean_exit(global);
}

int			handle_key(t_all *global, int key)
{
	if (key == 4283163)
		move_index_up(global);
	else if (key == 4348699)
		move_index_down(global);
	else if (key == 32)
		select_item(global);
	else if (key == 2117294875 || key == 127)
		delete_item(global);
	else if (key == 10)
		selection_finished(global);
	return (0);
}

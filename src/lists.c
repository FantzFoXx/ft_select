/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:04 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:06:13 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

void		t_item_push(t_item **items, t_item *new)
{
	t_item *index;
	t_item *first;

	index = *items;
	first = *items;
	if (!index)
	{
		*items = new;
		new->prev = new;
		new->ind = 1;
	}
	else
	{
		index->ind = 1;
		while (index->next)
			index = index->next;
		index->last = 0;
		index->next = new;
		new->prev = index;
	}
}

void		link_loop(t_item *first)
{
	t_item	*index;

	index = first;
	while (index->next)
		index = index->next;
	index->last = 1;
	index->next = first;
	first->prev = index;
}

static void	free_cur_item(t_item *cur)
{
	free(cur->item_name);
	free(cur);
}

int			item_delete(t_all *global, t_item *cur_item)
{
	if (cur_item->next != cur_item)
	{
		if (global->items == cur_item)
			global->items = cur_item->next;
		if (cur_item->last)
		{
			cur_item->prev->last = 1;
			cur_item->prev->ind = 1;
		}
		else
			cur_item->next->ind = 1;
		cur_item->next->prev = cur_item->prev;
		cur_item->prev->next = cur_item->next;
		free_cur_item(cur_item);
		return (1);
	}
	else
	{
		free_cur_item(cur_item);
		global->items = NULL;
		return (0);
	}
	return (1);
}

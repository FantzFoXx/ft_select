/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:04 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/25 20:03:03 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"
#include <stdlib.h>

t_item	*t_item_new(char *name)
{
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item));
	if (new)
	{
		new->item_name = name;
		new->select = 0;
		new->ind = 0;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

t_all	*t_all_new(void)
{
	t_all *new;

	new = (t_all *)malloc(sizeof(t_all));
	if (new)
	{
		new->term_name = NULL;
		new->items = NULL;
		new->is_printable = 1;
	}
	return (new);
}

void	t_item_push(t_item **items, t_item *new)
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

void	link_loop(t_item *first)
{
	t_item	*index;

	index = first;
	while (index->next)
		index = index->next;
	index->last = 1;
	index->next = first;
	first->prev = index;
}

int		item_delete(t_all *global, t_item *cur_item)
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
		return (1);
	}
	else
	{
		global->items = NULL;
		return (0);
	}
	return (1);
}

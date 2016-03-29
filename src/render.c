/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:18 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/29 19:27:25 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

void	set_item_mode(t_all *global, t_item *index)
{
	if (index->select && index->ind)
	{
		T_SETMODE("mr");
		T_SETMODE("us");
	}
	else if (index->ind)
		T_SETMODE("us");
	else if (index->select)
		T_SETMODE("mr");
}

size_t	max_len_col(t_all *global, t_item *begin)
{
	int		i;
	size_t	max_len;

	max_len = 0;
	i = 0;
	if (!begin->last)
		begin = begin->prev;
	while (!begin->last && i < global->ws.ws_row)
	{
		if (max_len < ft_strlen(begin->item_name))
			max_len = ft_strlen(begin->item_name);
		begin = begin->next;
		i++;
	}
	if (begin->last && max_len < ft_strlen(begin->item_name))
		max_len = ft_strlen(begin->item_name);
	return (max_len);
}

void	render_items(t_all *global)
{
	t_item	*index;
	int		x;
	int		y;
	int		fp;
	size_t	max_len;

	x = 0;
	y = 0;
	fp = 1;
	max_len = 0;
	clear_term(global);
	index = global->items;
	while (!index->prev->last || fp == 1)
	{
		fp = 0;
		if (x <= 1)
			max_len = max_len_col(global, index);
		if (x == global->ws.ws_row)
		{
			x = 0;
			y += max_len + 2;
		}
		T_GOTO(y, x);
		set_item_mode(global, index);
		T_PRINT(index->item_name);
		index = index->next;
		T_SETDFT_MODE;
		x++;
	}
	if (max_len + y >= global->ws.ws_col)
	{
		clear_term(global);
		T_PRINT("Not enough collumns to print items. The window must be larger");
		global->is_printable = 0;
	}
	else
	{
		/*
		set_item_mode(global, index);
		T_GOTO(y, x);
		//tputs(tgoto(T_GET_MODE("cm"), y, x), 0, t_putchar);
		T_PRINT(index->item_name);
		T_SETDFT_MODE;
		*/
		global->is_printable = 1;
	}
}

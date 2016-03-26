/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:18 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/26 14:22:23 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

void	set_item_mode(t_item *index)
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

size_t		max_len_col(t_all *global, t_item *begin)
{
	int i;
	size_t max_len;

	max_len = 0;
	i = 0;
	while (!begin->last && i < global->ws.ws_row)
	{
		if (max_len < ft_strlen(begin->item_name))
			max_len = ft_strlen(begin->item_name);
		begin = begin->next;
		i++;	
	}
	return (max_len);
}

void	render_items(t_all *global)
{
	t_item *index;
	int		x;
	int		y;
	size_t		max_len;

	x = 1;
	y = 1;
	max_len = 0;
	clear_term();
	index = global->items;
	while (!index->last)
	{
		if (x == 10)
		{
			max_len = max_len_col(global, index);
			if (y + max_len > global->ws.ws_col)
				break ;
			x = 0;
			y += max_len;
			max_len = 0;
		}
		set_item_mode(index);
		T_PRINT(index->item_name);
		tputs(tgoto(T_GET_MODE("cm"), y, x), 0, t_putchar);
		index = index->next;
		T_SETDFT_MODE;
		x++;
		//usleep(10000);
	}
	set_item_mode(index);
	T_PRINT(index->item_name);
	tputs(tgoto(T_GET_MODE("cm"), y, x), 0, t_putchar);
	T_SETDFT_MODE;
}

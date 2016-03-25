/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:18 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/25 14:42:09 by udelorme         ###   ########.fr       */
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

void	render_items(t_all *global)
{
	t_item *index;

	clear_term();
	index = global->items;
	while (!index->last)
	{
		set_item_mode(index);
		T_PRINT(index->item_name);
		tputs("\n", 0, t_putchar);
		index = index->next;
		T_SETDFT_MODE;
	}
	set_item_mode(index);
	T_PRINT(index->item_name);
	tputs("\n", 0, t_putchar);
	T_SETDFT_MODE;
}

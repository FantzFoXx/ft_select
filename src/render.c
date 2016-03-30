/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:18 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:07:57 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

static void	set_item_mode(t_all *global, t_item *index)
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

static void	goto_print(t_all *global, t_item *index, int x, int y)
{
	T_GOTO(y, x);
	set_item_mode(global, index);
	T_PRINT(index->item_name);
	T_SETDFT_MODE;
}

static void	check_printable(t_all *global, size_t max_len, int y)
{
	if (max_len + y >= global->ws.ws_col)
	{
		clear_term(global);
		T_PRINT(ERR_COL);
		global->is_printable = 0;
	}
	else
		global->is_printable = 1;
}

static void	repos_cursor(int *x, int *y, size_t *max_len)
{
	*x = 0;
	*y += *max_len + 2;
	*max_len = 0;
}

void		render_items(t_all *global)
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
	while (!index->prev->last || fp)
	{
		fp = 0;
		if (x == global->ws.ws_row)
			repos_cursor(&x, &y, &max_len);
		goto_print(global, index, x, y);
		if (max_len < ft_strlen(index->item_name))
			max_len = ft_strlen(index->item_name);
		index = index->next;
		x++;
	}
	check_printable(global, max_len, y);
}

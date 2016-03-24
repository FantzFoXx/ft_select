/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:18 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:34 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "toolkit.h"
#include "ft_select.h"

void	render_items(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->last)
	{
		if (index->select)
			tputs(tgetstr("mr", NULL), 0, t_putchar);
		tputs(index->item_name, 0, t_putchar);
		tputs("\n", 0, t_putchar);
		index = index->next;
		tputs(tgetstr("me", NULL), 0, t_putchar);
	}
}

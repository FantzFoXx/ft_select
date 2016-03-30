/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_creates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:48:12 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 17:58:54 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

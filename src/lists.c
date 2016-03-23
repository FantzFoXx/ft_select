#include "libft.h"
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
	}
	else
	{
		while (index->next)
			index = index->next;
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
	index->next = first;
	first->prev = index;
}

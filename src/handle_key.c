#include "ft_select.h"
//#include "libft.h"
#include <stdio.h>
#include "toolkit.h"

void	move_index_up(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->prev;
	index->ind = 0;
	index->prev->ind = 1;
}

void	move_index_down(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	index->ind = 0;
	index->next->ind = 1;
}

void	select_item(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	if (!index->select)
	{
		move_index_down(global);
		index->select = 1;
	}
	else	
		index->select = 0;
}

void	delete_item(t_all *global)
{
	t_item *index;

	index = global->items;
	while (!index->ind)
		index = index->next;
	if (item_delete(global, index) == 0)
		clean_exit(global);
}

int		handle_key(t_all *global, int key)
{
	if (key == 4283163)
		move_index_up(global);
	else if (key == 4348699)
		move_index_down(global);
	else if (key == 32)
		select_item(global);
	else if (key == 2117294875 || key ==  127)
		delete_item(global);
	else if (key == 10)
		selection_finished(global);
	return (0);
}

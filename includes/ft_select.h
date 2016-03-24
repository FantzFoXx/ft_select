/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:22 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:36 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>

typedef struct	s_item
{
	char			*item_name;
	int				select;
	int				last;
	struct s_item	*next;
	struct s_item	*prev;
}				t_item;

typedef struct	s_all
{
	char			*term_name;
	struct winsize	ws;
	struct termios	term;
	t_item			*items;
}				t_all;

int		init_env(t_all *global, char **av);
t_all	*t_all_new(void);
t_item	*t_item_new(char *name);
void	t_item_push(t_item **items, t_item *new);
void	link_loop(t_item *first);
void	render_items(t_all *global);

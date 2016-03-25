/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:22 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/25 17:41:10 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <unistd.h>
#include <termios.h>
#include <term.h>

#define T_PRINT(x) tputs(x, 0, t_putchar)
#define T_GET_MODE(x) tgetstr(x, NULL)
#define T_SETMODE(x) tputs(T_GET_MODE(x), 0, t_putchar)
#define	T_SETDFT_MODE T_SETMODE("me")

typedef struct	s_item
{
	char			*item_name;
	int				select;
	int				last;
	int				ind;
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
int		rst_termios(t_all *global);
t_all	*t_all_new(void);
t_item	*t_item_new(char *name);
void	t_item_push(t_item **items, t_item *new);
void	link_loop(t_item *first);
void	render_items(t_all *global);
int		handle_key(t_all *global, int key);
int		item_delete(t_all *global, t_item *cur_item);
void	clean_exit(t_all *global);
void	selection_finished(t_all *global);
void	init_signal_handling(void);
t_all	*return_global(t_all *global);

#endif

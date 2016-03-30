/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolkit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:22:29 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/30 18:08:25 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLKIT_H
# define TOOLKIT_H

# include "ft_select.h"

# define ERR_COL "Not enough collumns to print items. The window must be larger"

int		t_putchar(int c);
void	clear_term(t_all *global);

#endif

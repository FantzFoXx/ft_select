# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udelorme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 11:43:18 by udelorme          #+#    #+#              #
#    Updated: 2016/03/28 09:27:57 by udelorme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wall -Werror -Wextra -g
NAME = ft_select
SRC = main.c init_properties.c lists.c	\
	  toolkit.c render.c handle_key.c	\
	  catch_signal.c

OBJ = $(SRC:.c=.o)

SRCDIR = src/
OBJDIR = obj/
INCDIR = includes/
LIBDIR = libft/

SRCS = $(addprefix $(SRCDIR),$(SRC))
OBJS = $(addprefix $(OBJDIR),$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	$(CC) -L $(LIBDIR) -lft -ltermcap $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(FLAGS) -I $(INCDIR) -I $(LIBDIR)includes -o $@ -c $<

clean:
	rm -rf $(OBJS)
	@rmdir $(OBJDIR) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)

re: fclean all

lftclean:
	$(MAKE) -C $(LIBDIR) clean

lftfclean:
	$(MAKE) -C $(LIBDIR) fclean

.PHONY: all clean fclean re

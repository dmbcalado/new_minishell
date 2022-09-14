# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:21:37 by anfreire          #+#    #+#              #
#    Updated: 2022/09/14 22:27:52 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard ./srcs/parsing/*.c) $(wildcard ./srcs/redirections/*.c) $(wildcard ./srcs/frees/*.c) $(wildcard ./srcs/builtins/*.c) $(wildcard ./srcs/env/*.c) $(wildcard ./srcs/signals/*.c) $(wildcard ./srcs/commands/*.c) $(wildcard ./srcs/*.c) $(wildcard ./srcs/utils/*.c) $(wildcard ./libft/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS		= -g -Wall -Wextra -Werror -lreadline -ltinfo -fsanitize=address

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		@stty -ctlecho
# 	|stty -ctlecho : silenciar input de ctrl
#	|-->reverter : stty -a
		@gcc -o $(NAME) $(OBJS) $(CFLAGS)
		@echo	""
		@echo	"$$ ./minishell && Object Files Generated"
		@echo	""
%.o			:	%.c
		@gcc $(CFLAGS) -c $^ -I./ -o $@

clean		:
		@rm -f $(OBJS)
		@echo	""
		@echo	"$$ Object Files Deleted"
		@echo	""

fclean		:	clean
		@rm -f $(NAME)
		@echo	""
		@echo	"$$ ./minishell Deleted"
		@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus
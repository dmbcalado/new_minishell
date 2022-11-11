# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:21:37 by anfreire          #+#    #+#              #
#    Updated: 2022/11/07 15:51:49 by anfreire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard ./srcs/parsing/*.c) $(wildcard ./gnl/*.c) $(wildcard ./srcs/redirections/*.c) $(wildcard ./srcs/frees/*.c) $(wildcard ./srcs/builtins/*.c) $(wildcard ./srcs/env/*.c) $(wildcard ./srcs/signals/*.c) $(wildcard ./srcs/commands/*.c) $(wildcard ./srcs/*.c) $(wildcard ./srcs/utils/*.c) $(wildcard ./libft/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS		= -g -Wall -Wextra -Werror -lreadline -ltinfo -fsanitize=address

all	:	$(NAME)


$(NAME)	:	$(OBJS)
		@stty -ctlecho
# 	|stty -ctlecho : silenciar input de ctrl
#	|-->reverter : stty -a
		@gcc -o $(NAME) $(OBJS) $(CFLAGS)
		@echo	""
		@echo	"$$ ./minishell && Object Files Generated"
		@echo	""
		@echo	""
		@echo	""
		@echo -e "\e[34m           :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::	"
		@echo -e "         :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:  "
		@echo -e "       +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+   "
		@echo -e "      +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+    "
		@echo -e "     +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+     "
		@echo -e "    #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#      "
		@echo -e "   ###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########"
		@echo -e ""
		@echo -e "\e[32mVersion : 0.0.1"
		@echo -e ""
		@echo -e "\e[0mThis replication of the bash shell runs commands, redirections and has some builtin commands."
		@echo -e "You're able to fully check the objectives on this project by checking the file subject.pdf."
		@echo -e "So we hope you enjoy going through this software half as much as we enjoyed making it for you,"
		@echo -e "because we had a ball."
		@echo -e ""
		@echo -e "\e[34mnow run ./minishell and welcome!"
		@echo -e ""
		@echo -e "\e[0mWork made by:"
		@echo -e "Diogo MBM Calado and Andre Freire, from 42 Lisbon."
		@echo -e ""
		@echo -e ""
		@echo -e ""
		
%.o	:	%.c
	@gcc $(CFLAGS) -c $^ -I./ -o $@
	

clean	:
	@rm -f $(OBJS)
	@echo	""
	@echo	"$$ Object Files Deleted"
	@echo	""
		
fclean	:	clean
	@rm -f $(NAME)
	@echo	""
	@echo	"$$ ./minishell Deleted"
	@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus
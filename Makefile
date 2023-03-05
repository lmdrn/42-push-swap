# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 17:11:18 by lmedrano          #+#    #+#              #
#    Updated: 2023/03/05 14:18:18 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

SRCS 		= srcs/main.c \
		  	  srcs/swap.c \
			  srcs/push.c \
			  srcs/rotate.c \
			  srcs/revrotate.c \
			  srcs/arguments.c \
		  	  srcs/small_sort.c \
		  	  srcs/big_sort.c \
		  	  srcs/list_manipulations.c \
		      srcs/push_swap_utils.c \
		  	  srcs/index.c

OBJS 		= ${SRCS:.c=.o}

NAME		= push_swap

CC 			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

LIB 		= -L./libft -lft

${NAME}:	${OBJS}
			@echo "$(RESET)$(ORANGE)ASSEMBLING $(NAME)$(RESET)"
			make -C libft
			${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
			@echo "$(RESET)$(GREEN)$(NAME) HAS ASSEMBLED ✓$(RESET)"

all:		header $(NAME)

header:	
			@echo "$(BLUE)                           $(RESET)"
			@echo "$(BLUE)       Welcome mon p'tit ! $(RESET)"
			@echo "$(BLUE)        ___  _____ ___  ___      _        $(RESET)"
			@echo "$(BLUE)       /   |/ __  \|  \/  |     | |        $(RESET)"
			@echo "$(BLUE)      / /| |\`' / /'| .  . | __ _| | _____  $(RESET)"
			@echo "$(BLUE)     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\ $(RESET)"
			@echo "$(BLUE)     \___  |./ /___| |  | | (_| |   <  __/ $(RESET)"
			@echo "$(BLUE)         |_/\_____/\_|  |_/\__,_|_|\_\___|......I'm so badass wesh $(RESET)"
			@echo "$(BLUE)                           $(RESET)"

# test:		all
# 			${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
# 			./${NAME} "3 2 1"
		
clean:		
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			make clean -C libft
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			rm -f libft/libft.a
			${RM} ${OBJS} ${NAME}
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all test clean fclean re

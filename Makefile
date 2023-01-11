# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 17:11:18 by lmedrano          #+#    #+#              #
#    Updated: 2023/01/11 15:16:27 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE = \033[38;5;69m
ORANGE = \033[38;5;215m
GREEN = \033[38;5;82m
RESET = \033[0m

SRCS 		= srcs/main.c \
		  srcs/push_swap_utils.c

OBJS 		= ${SRCS:.c=.o}

NAME		= push_swap

CC 		= gcc

CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf

LIB 		= -L./libft -lft

.c.o:
		@echo "$(RESET)$(ORANGE)COMPILING $^:$(RESET) "
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		@echo "$(RESET)$(GREEN)$(NAME) HAS COMPILED ✓$(RESET)"

${NAME}:	${OBJS}
		@echo "$(RESET)$(ORANGE)ASSEMBLING $(NAME)$(RESET)"
		make -C libft
		${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
		@echo "$(RESET)$(GREEN)$(NAME) HAS ASSEMBLED ✓$(RESET)"

all:		header $(NAME)

header:	
		@echo "$(BLUE)                           $(RESET)"
		@echo "$(BLUE)       Welcome mon p'tit ! $(RESET)"
		@echo "$(BLUE)       ___  _____ ___  ___      _        $(RESET)"
		@echo "$(BLUE)      /   |/ __  \|  \/  |     | |        $(RESET)"
		@echo "$(BLUE)      / /| |\`' / /'| .  . | __ _| | _____  $(RESET)"
		@echo "$(BLUE)     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\ $(RESET)"
		@echo "$(BLUE)     \___  |./ /___| |  | | (_| |   <  __/ $(RESET)"
		@echo "$(BLUE)         |_/\_____/\_|  |_/\__,_|_|\_\___|......I'm so badass wesh $(RESET)"
		@echo "$(BLUE)                           $(RESET)"

checker:		
		ARG="4 67 3 87 23"; ./${NAME} $$ARG | wc-l
		ARG="4 67 3 87 23"; ./${NAME} $$ARG | ./checker_Mac $$ARG

test:		all
		${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
		./${NAME} "5 2 7 1 6 3 9 4 8"		
		
clean:		
		@echo "$(RESET)$(ORANGE)I'M CLEANING UP MY CLOSET...$(RESET)"
		${RM} ${OBJS}
		@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
		@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
		${RM} ${NAME}
		rm -f libft/libft.a
		@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:		fclean all

.PHONY:		all checker test clean fclean re

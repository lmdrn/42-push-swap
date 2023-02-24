# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:51:11 by lmedrano          #+#    #+#              #
#    Updated: 2022/10/30 18:14:55 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_split.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_strtrim.c ft_putnbr_fd.c ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_calloc.c ft_strdup.c ft_strnstr.c ft_atoi.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_memchr.c ft_strlen.c ft_isascii.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_memset.c 

OBJS		= ${SRCS:.c=.o}

BONUS		= ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c

BOBJS		= ${BONUS:.c=.o}

NAME		= libft.a

CC			= gcc

ARRC		= ar rc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${ARRC} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS} ${BOBJS}
			${ARRC} ${NAME} ${OBJS} ${BOBJS}

clean:	
			${RM} ${OBJS} ${BOBJS}

fclean: 	clean 
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re bonus

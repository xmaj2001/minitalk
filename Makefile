# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/06/25 14:49:35 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

IS		= ./libft/is/
MEM		= ./libft/mem/
PRINT	= ./libft/print/
PRINTF	= ./libft/printf/
STRING	= ./libft/string/
CONVERT	= ./libft/convert/
		
FLAGS	= -Wall -Werror -Wextra


all:$(NAME)

bonus:
	cc $(FLAGS) -o server_bonus server_bonus.c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c minitalk_utils.c -I ./libft/
	clear
	cc $(FLAGS) -o client_bonus client_bonus.c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c  minitalk_utils.c -I ./libft/
	clear

$(NAME):
	cc $(FLAGS) -o server server.c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c minitalk_utils.c -I ./libft/
	clear
	cc $(FLAGS) -o client client.c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c  minitalk_utils.c -I ./libft/
	clear

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
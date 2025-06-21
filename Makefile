# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 14:02:35 by raydogmu          #+#    #+#              #
#    Updated: 2025/05/29 14:02:35 by raydogmu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c sources/arg.c sources/init.c sources/init1.c \
	sources/monitor.c sources/others.c sources/print.c sources/threads.c \
	sources/timestamp.c
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

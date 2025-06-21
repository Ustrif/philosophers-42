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

SRC = main.c sources/*.c #düzenle.
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

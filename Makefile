SRC = main.c sources/*.c #düzenle.
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -rf $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean fclean re
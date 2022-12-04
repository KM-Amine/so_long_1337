NAME = valid_path
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf
HEADER  = minitalk.h
CLIENT = client
SERVER = server


SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIBFT = custom_libft/libft.a 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ)  -o $(NAME) 

$(LIBFT) :
	$(MAKE) -C custom_libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< 

clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C custom_libft
fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
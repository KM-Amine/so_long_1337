NAME = game
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I ./includes 
RM = rm -rf
HEADER  = includes/so_long.h
CLIENT = client
SERVER = server


SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=objs/%.o)
LIBFT = custom_libft/libft.a 

LSRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_printf.c \
	ft_printf_utils.c \
	get_next_line.c \

LOBJ =$(LSRC:%.c=custom_libft/%.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT) : $(LOBJ)
	$(MAKE) -C custom_libft

objs/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

custom_libft/%.o: custom_libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C custom_libft
fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
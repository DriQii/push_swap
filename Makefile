NAME = exe

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c \
		src/utils.c \
		src/lst_init.c \
		src/instructions1.c \
		src/instructions2.c \
		src/instructions3.c \

OBJ = $(SRC:.c=.o)

LIB = ft

LIBDIR = libft

all : $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) -I include -c $< -o $@

$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a lib
	$(CC) $(CFLAGS) $(OBJ) -I include -L $(LIBDIR) -l  $(LIB) -o $(NAME)

clean :
	make clean -C libft
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

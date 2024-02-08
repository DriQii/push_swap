NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -g

SRC =	src/main.c \
		src/utils.c \
		src/amoove.c \
		src/bmoove.c \
		src/lst_init.c \
		src/check_moove.c \
		src/check_moove_2.c \
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
	make clean -C my_checker
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	make fclean -C libft
	make fclean -C my_checker
	rm -rf $(NAME)

re : fclean all

bonus :
	make -C my_checker

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	utils.c \
		checker.c \
		lst_init.c \
		instructions1.c \
		instructions2.c \
		instructions3.c \

OBJ = $(SRC:.c=.o)

LIB = ft

LIBDIR = ../libft

all : $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) -I include -c $< -o $@

$(NAME) : $(OBJ)
	make -C ../libft
	cp ../libft/libft.a ../lib
	$(CC) $(CFLAGS) $(OBJ) -I include -L $(LIBDIR) -l  $(LIB) -o $(NAME)
	cp $(NAME) ../$(NAME)
	rm -f $(NAME)

clean :
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	rm -rf ../$(NAME)

re : fclean all

NAME = fillit

SRCS = \
	   main.c		\
	   input.c		\
	   t_tet.c		\
	   t_col.c		\
	   translate.c	\
	   env.c		\
	   grid.c		\
	   shift.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -Wall -Werror -Wextra -c $(SRCS) -I libft
	gcc -L libft -lft $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

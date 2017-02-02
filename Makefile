NAME = fillit

SRCS = \
	   main.c		\
	   input.c		\
	   t_tet.c

OBJS = $(SRCS:.c=.o)

HEADER = includes/fillit.h

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Iincludes -o $(NAME) -Wall -Wextra -Werror $(OBJS)

$(OBJS): $(SRCS) $(HEADER)
	gcc -Iincludes -Wall -Werror -Wextra -c  srcs/$(SRCS)

clean: 
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

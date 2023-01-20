DIRLIB = ./libft/

DIRINC = ./includes/

DIRSRC = ./srcs/

SRC =	push_swap \
		push_swap_utils \
		push_swap_utils2 \
		moves \
		t_alist \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

NAME = push_swap.a
NAMELIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAMELIBFT):
	make all -C $(DIRLIB)

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o push_swap

bonus: $(NAMELIBFT)
#	...

clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
	rm -f push_swap

re: fclean all

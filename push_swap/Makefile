DIRLIB = ./libft/

DIRINC = ./includes/

DIRSRC = ./srcs/

SRC =	push_swap \
		push_swap_utils \
		push_swap_utils2 \
		sort_utils \
		moves \
		t_alist \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = $(SRCS:%.c=%.o)

NAMELIBFT = libft.a
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAMELIBFT):
	make all -C $(DIRLIB)

$(NAME): $(OBJS) $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o push_swap

clean:
	make clean -C $(DIRLIB)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(DIRLIB)
	rm -f push_swap

re: fclean all

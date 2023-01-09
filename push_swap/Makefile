DIRLIB = ./libft/

DIRINC = ./includes/

DIRSRC = ./srcs/

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
#	...

bonus: $(NAMELIBFT)
#	...

clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
#	...

re: fclean all
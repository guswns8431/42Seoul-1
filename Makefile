NAME = checker
NAME2 = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
FUNC = checker.c \
	error_exit.c make_stack_list.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c \
	make_inst_list.c
FUNC2 = push_swap.c \
	error_exit.c make_stack_list.c examine_sort.c \
	execute_p.c execute_r.c execute_s.c execute_inst.c

C_SRCS = $(addprefix ./srcs/, $(FUNC))
C_OBJS = $(addprefix ./objs/, $(FUNC:.c=.o))
P_SRCS = $(addprefix ./srcs/, $(FUNC2))
P_OBJS = $(addprefix ./objs/, $(FUNC2:.c=.o))
INC = -I./libft/includes/ -I.
LIBFT = -L./libft -lft
DEBUG = -g3 -fsanitize=address

./objs/%.o : ./srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $?

all : $(NAME) $(NAME2)

$(NAME) : $(C_OBJS)
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

$(NAME2) : $(P_OBJS)
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(DEBUG) $^ -o $@

clean :
	rm -f $(C_OBJS) $(P_OBJS)

fclean : clean
	rm -f $(NAME) $(NAME2)

re : fclean all

.PHONY : clean fclean re

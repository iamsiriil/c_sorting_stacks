NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -DDEBUG
RM = rm -f

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

HDRS_LST = push_swap.h
TEST_HDRS = test_push_swap.h

SOURCE_FILES = ps_utils.c \
	ps_parser.c \
	ps_check.c \
	ps_clist.c \
	ps_error.c \
	ps_main.c \
	ps_opr_push.c \
	ps_opr_swap.c \
	ps_opr_rotation.c \
	ps_opr_rev_rotation.c \
	ps_small_sort.c \
	ps_radix_sort.c \
	test_ps_utils.c

OBJS = $(SOURCE_FILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(CFLAGS)  -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
	

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parrot <parrot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 14:32:56 by toantune          #+#    #+#              #
#    Updated: 2024/04/01 14:34:22 by parrot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = ./libft/
LIBFT_HDR = $(LIBFT_DIR)include/
LIBFT = $(LIBFT_DIR)libft.a

HDRS_LST = push_swap.h
HDRS_DIR = ./includes/
HDRS = $(addprefix $(HDRS_DIR), $(HDRS_LST))

SOURCE_FILES = ps_main.c \ 
	ps_errors.c \
	ps_operations.c \
	ps_utils.c



CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

FILE = 

all: $(NAME)

clean:
	$(RM) 

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
	

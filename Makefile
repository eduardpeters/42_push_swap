# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epeters- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:56:05 by epeters-          #+#    #+#              #
#    Updated: 2022/11/27 18:54:55 by epeters-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./include

DIR_SRCS	= src
DIR_LIBFT	= libft

SRCS =	push_swap.c parse_arguments.c split_arguments.c manage_stack.c \
		stack_rotations.c stack_swaps.c stack_pushes.c route_sort.c \
		sorting_a.c sorting_b.c sort_chunk_a.c chunk_helpers.c \
		sort_three.c sort_four.c

OBJS = $(addprefix $(DIR_SRCS)/,$(SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo Compiling $(NAME)...
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

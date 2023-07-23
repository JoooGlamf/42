# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 02:30:52 by soojoo            #+#    #+#              #
#    Updated: 2023/07/23 14:05:14 by soojoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAG	= -Wall -Wextra -Werror   

PUSH_SWAP_SRCS = \
	check.c \
	command1.c \
	command2.c \
	command3.c \
	pre_command.c \
	push_swap.c \
	select_number.c \
	sort.c \
	stack1.c \
	stack2.c

LIBFT_SRCS = \
	libft/ft_memset.c \
	libft/ft_strjoin.c \
	libft/ft_calloc.c \
	libft/ft_split.c \
	libft/ft_strncmp.c \
	libft/ft_atoi.c \
	libft/ft_strlen.c

FT_PRINTF_SRCS = \
	ft_printf/ft_printf.c \
	ft_printf/print_char.c \
	ft_printf/print_hex.c \
	ft_printf/print_int_unsigned.c \
	ft_printf/print_int.c \
	ft_printf/print_percent.c \
	ft_printf/print_pointer.c \
	ft_printf/print_str.c

PUSH_SWAP_OBJS =  $(PUSH_SWAP_SRCS:.c=.o)
LIBFT_OBJS =  $(LIBFT_SRCS:.c=.o)
FT_PRINTF_OBJS =  $(FT_PRINTF_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(PUSH_SWAP_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(PUSH_SWAP_OBJS) $(LIBFT_OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:30:39 by soojoo            #+#    #+#              #
#    Updated: 2023/07/03 11:30:55 by soojoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

PIPEX_SRCS = \
	pipex.c \
	redirect.c \
	utils.c

LIBFT_SRCS = \
	libft/ft_memset.c \
	libft/ft_strjoin.c \
	libft/ft_calloc.c \
	libft/ft_split.c \
	libft/ft_strncmp.c

FT_PRINTF_SRCS = \
	ft_printf/ft_printf.c \
	ft_printf/print_char.c \
	ft_printf/print_hex.c \
	ft_printf/print_int_unsigned.c \
	ft_printf/print_int.c \
	ft_printf/print_percent.c \
	ft_printf/print_pointer.c \
	ft_printf/print_str.c

PIPEX_OBJS =  $(PIPEX_SRCS:.c=.o)
LIBFT_OBJS =  $(LIBFT_SRCS:.c=.o)
FT_PRINTF_OBJS =  $(FT_PRINTF_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(PIPEX_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(PIPEX_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean : 
	rm -rf $(PIPEX_OBJS) $(LIBFT_OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

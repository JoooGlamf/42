# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 22:52:59 by soojoo            #+#    #+#              #
#    Updated: 2023/04/05 13:52:26 by soojoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC		= cc
CFLAG		= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar
ARFLAGS	= crs
INCLUDES	= ./ft_printf.h 
SRCS = \
      ft_printf.c \
      print_char.c \
      print_hex.c \
      print_int.c \
      print_int_unsigned.c \
      print_percent.c \
      print_pointer.c \
      print_str.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re

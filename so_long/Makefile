NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SO_LONG_SRCS = \
	so_long.c \
	read_map.c \
	check_map1.c \
	check_map2.c \
	image.c \
	input.c
GNL_SRCS = \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
FT_PRINTF_SRCS = \
	ft_printf/ft_printf.c \
	ft_printf/print_char.c \
	ft_printf/print_hex.c \
	ft_printf/print_int_unsigned.c \
	ft_printf/print_int.c \
	ft_printf/print_percent.c \
	ft_printf/print_pointer.c \
	ft_printf/print_str.c

SO_LONG_OBJS =  $(SO_LONG_SRCS:.c=.o)
GNL_OBJS =  $(GNL_SRCS:.c=.o)
FT_PRINTF_OBJS =  $(FT_PRINTF_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(GNL_OBJS) $(FT_PRINTF_OBJS) $(SO_LONG_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) -L./mlx -lmlx -framework OpenGL -framework AppKit  $(SO_LONG_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

$(GNL_OBJS) : $(GNL_SRCS)
	$(CC) $(CFLAGS) -c -o get_next_line/get_next_line.o get_next_line/get_next_line.c
	$(CC) $(CFLAGS) -c -o get_next_line/get_next_line_utils.o get_next_line/get_next_line_utils.c

$(FT_PRINTF_OBJS) : $(FT_PRINTF_SRCS)
	$(CC) $(CFLAGS) -c -o ft_printf/ft_printf.o ft_printf/ft_printf.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_char.o ft_printf/print_char.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_hex.o ft_printf/print_hex.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_int_unsigned.o ft_printf/print_int_unsigned.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_int.o ft_printf/print_int.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_percent.o ft_printf/print_percent.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_pointer.o ft_printf/print_pointer.c
	$(CC) $(CFLAGS) -c -o ft_printf/print_str.o ft_printf/print_str.c

$(SO_LONG_OBJS) : $(SO_LONG_SRCS)
	cc $(CFLAGS) -c $(SO_LONG_SRCS)

clean : 
	rm -rf $(SO_LONG_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
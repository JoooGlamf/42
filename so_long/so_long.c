/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:45:33 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 11:00:28 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	print_err(char *message)
{
	perror(message);
	exit_game(1);
}

void	exit_game(int error)
{
	if (error)
		exit(1);
	else
		exit(0);
}

int	x_button(int keycode, t_info *info)
{
	(void)keycode;
	(void)info;
	exit_game(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info		*game_info;

	if (argc != 2)
		print_err("Error\nInvalid number of arguments");
	if (!valid_argv(argv[1]))
		print_err("Error\nInvalid arguments");
	game_info = (t_info *)malloc(sizeof(t_info));
	if (!game_info)
		print_err("malloc error!");
	game_info->map = 0;
	game_info->map = read_map(game_info, argv[1]);
	check_letters(game_info);
	check_cpe(game_info);
	check_rectangle(game_info);
	check_surrounded(game_info);
	check_clearable(game_info);
	game_info->mlx = mlx_init();
	game_info->window = mlx_new_window(game_info->mlx,
			game_info->width * 32, game_info->height * 32, "so_long");
	get_image(game_info);
	draw_image(game_info);
	mlx_hook(game_info->window, 3, 0, &get_input, game_info);
	mlx_hook(game_info->window, 17, 0, &x_button, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}

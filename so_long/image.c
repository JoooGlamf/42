/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:54:31 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 11:05:49 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	get_image(t_info *game_info)
{
	game_info->images.player.addr = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/player.xpm", &(game_info->images.player.width),
			&(game_info->images.player.height));
	game_info->images.collectible.addr = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/box.xpm", &(game_info->images.collectible.width),
			&(game_info->images.collectible.height));
	game_info->images.empty_space.addr = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/grass.xpm", &(game_info->images.empty_space.width),
			&(game_info->images.empty_space.height));
	game_info->images.wall.addr = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/stone.xpm", &(game_info->images.player.width),
			&(game_info->images.player.height));
	game_info->images.exit.addr = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/exit.xpm", &(game_info->images.exit.width),
			&(game_info->images.exit.height));
}

void	draw_image(t_info *game_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game_info->height)
	{
		j = -1;
		while (++j <= game_info->width)
		{
			mlx_put_image_to_window(game_info->mlx, game_info->window,
				game_info->images.empty_space.addr, j * 32, i * 32);
			if (game_info->map[(game_info->width + 1) * i + j] == '1')
				mlx_put_image_to_window(game_info->mlx, game_info->window,
					game_info->images.wall.addr, j * 32, i * 32);
			else if (game_info->map[(game_info->width + 1) * i + j] == 'C')
				mlx_put_image_to_window(game_info->mlx, game_info->window,
					game_info->images.collectible.addr, j * 32, i * 32);
			else if (game_info->map[(game_info->width + 1) * i + j] == 'E')
				mlx_put_image_to_window(game_info->mlx, game_info->window,
					game_info->images.exit.addr, j * 32, i * 32);
			else if (game_info->map[(game_info->width + 1) * i + j] == 'P')
				mlx_put_image_to_window(game_info->mlx, game_info->window,
					game_info->images.player.addr, j * 32, i * 32);
		}
	}
}

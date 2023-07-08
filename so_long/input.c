/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:34:53 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/08 13:56:47 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	get_input(int keycode, t_info *game_info)
{
	static int	walk_count;

	if (keycode == 13)
		move_w_13(game_info);
	else if (keycode == 0)
		move_a_0(game_info);
	else if (keycode == 1)
		move_s_1(game_info);
	else if (keycode == 2)
		move_d_2(game_info);
	else if (keycode == 53)
		exit_game(0);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		++walk_count;
		ft_printf("walk count:%d\n", walk_count);
		ft_printf("collectible:%d\n", game_info->count_collectible);
	}
	draw_image(game_info);
	return (0);
}

void	move_w_13(t_info *i)
{
	if (i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid] == 'C')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid] = 'P';
		i->player.hei -= 1;
		i->count_collectible -= 1;
	}
	else if (i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid]
		== 'E')
	{
		if (i->count_collectible == 0)
		{
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
			i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid]
				= 'P';
			exit_game(0);
		}
	}
	else if (i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid]
		== '0')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei - 1) * (i->width + 1) + i->player.wid] = 'P';
		i->player.hei -= 1;
	}
}

void	move_a_0(t_info *i)
{
	if (i->map[i->player.hei * (i->width + 1) + i->player.wid - 1] == 'C')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid - 1] = 'P';
		i->player.wid -= 1;
		i->count_collectible -= 1;
	}
	else if (i->map[(i->player.hei) * (i->width + 1) + i->player.wid - 1]
		== 'E')
	{
		if (i->count_collectible == 0)
		{
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid - 1]
				= 'P';
			exit_game(0);
		}
	}
	else if (i->map[(i->player.hei) * (i->width + 1) + i->player.wid - 1]
		== '0')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid - 1] = 'P';
		i->player.wid -= 1;
	}
}

void	move_s_1(t_info *i)
{
	if (i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid] == 'C')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid] = 'P';
		i->player.hei += 1;
		i->count_collectible -= 1;
	}
	else if (i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid]
		== 'E')
	{
		if (i->count_collectible == 0)
		{
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
			i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid]
				= 'P';
			exit_game(0);
		}
	}
	else if (i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid]
		== '0')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei + 1) * (i->width + 1) + i->player.wid] = 'P';
		i->player.hei += 1;
	}
}

void	move_d_2(t_info *i)
{
	if (i->map[i->player.hei * (i->width + 1) + i->player.wid + 1] == 'C')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid + 1] = 'P';
		i->player.wid += 1;
		i->count_collectible -= 1;
	}
	else if (i->map[(i->player.hei) * (i->width + 1) + i->player.wid + 1]
		== 'E')
	{
		if (i->count_collectible == 0)
		{
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
			i->map[(i->player.hei) * (i->width + 1) + i->player.wid + 1]
				= 'P';
			exit_game(0);
		}
	}
	else if (i->map[(i->player.hei) * (i->width + 1) + i->player.wid + 1]
		== '0')
	{
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid] = '0';
		i->map[(i->player.hei) * (i->width + 1) + i->player.wid + 1] = 'P';
		i->player.wid += 1;
	}
}

//game_info->player.height = i / (game_info->width + 1);
//game_info->player.width = i % (game_info->width + 1);

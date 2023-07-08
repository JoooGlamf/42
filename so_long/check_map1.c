/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:22:11 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 10:47:14 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_cpe(t_info *game_info)
{
	int	check_e;
	int	check_p;
	int	i;

	game_info->count_collectible = 0;
	check_e = 0;
	check_p = 0;
	i = -1;
	while (++i < ft_strlen(game_info->map))
	{
		if (game_info->map[i] == 'C')
			game_info->count_collectible += 1;
		else if (game_info->map[i] == 'P')
		{
			game_info->player.hei = i / (game_info->width + 1);
			game_info->player.wid = i % (game_info->width + 1);
			check_p += 1;
		}
		else if (game_info->map[i] == 'E')
			check_e += 1;
	}
	if (game_info->count_collectible && (check_e == 1) && (check_p == 1))
		return ;
	print_err("Error\nComponents(C, P, E) Error!");
}

void	check_rectangle(t_info *game_info)
{
	if (ft_strlen(game_info->map) + 1
		!= (game_info->width + 1) * game_info->height)
		print_err("Error\nMap is not rectangle!");
}

void	check_surrounded(t_info *info)
{
	int	i;

	i = 1;
	while (i <= info->height)
	{
		if (info->map[(info->width + 1) * i - 2] != '1')
			print_err("Error\nMap is not surrounded!");
		++i;
	}
	i = 0;
	while (i < info->height)
	{
		if (info->map[(info->width + 1) * i] != '1')
			print_err("Error\nMap is not surrounded!");
		++i;
	}
	i = 0;
	while (i < info->width)
	{
		if (info->map[i] != '1')
			print_err("Error\nMap is not surrounded!");
		if (info->map[(info->width + 1) * (info->height - 1) + i] != '1')
			print_err("Error\nMap is not surrounded!");
		++i;
	}
}

void	check_letters(t_info *game_info)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (game_info->map[i])
	{
		if (game_info->map[i] == '0' || game_info->map[i] == '1'
			|| game_info->map[i] == 'P' || game_info->map[i] == 'E'
			|| game_info->map[i] == 'C')
			++i;
		else if (game_info->map[i] == '\n' && ((i + 1)
				% (game_info->width + 1) == 0)
			&& i < (ft_strlen(game_info->map) - 1))
			++i;
		else
			break ;
	}
	if (i != ft_strlen(game_info->map))
		print_err("Error\nFind Strange Letter!");
}

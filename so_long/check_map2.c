/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 06:07:52 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 08:53:59 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strdup(const char *string)
{
	int		count;
	char	*ch_p;
	int		i;

	count = 0;
	while (string[count])
		count++;
	ch_p = (char *)malloc(sizeof(char) * (count + 1));
	if (!ch_p)
		return (0);
	i = -1;
	while (string[++i])
		ch_p[i] = string[i];
	ch_p[i] = 0;
	return (ch_p);
}

//game_info->player.height = i / (game_info->width + 1);
//game_info->player.width = i % (game_info->width + 1);
int	dfs(int p_h, int p_w, char *t_m, t_width_count w_c)
{
	int	i;

	if (t_m[p_h * (w_c.width + 1) + p_w] == 'C')
	{
		i = -1;
		while (t_m[++i])
			if (t_m[i] == 'V')
				t_m[i] = '0';
		t_m[p_h * (w_c.width + 1) + p_w] = 'V';
		--(w_c.count);
		return (dfs(p_h - 1, p_w, t_m, w_c) || dfs(p_h, p_w - 1, t_m, w_c)
			|| dfs(p_h + 1, p_w, t_m, w_c) || dfs(p_h, p_w + 1, t_m, w_c));
	}
	if (t_m[p_h * (w_c.width + 1) + p_w] == '0'
		|| t_m[p_h * (w_c.width + 1) + p_w] == 'P')
	{
		t_m[p_h * (w_c.width + 1) + p_w] = 'V';
		return (dfs(p_h - 1, p_w, t_m, w_c) || dfs(p_h, p_w - 1, t_m, w_c)
			|| dfs(p_h + 1, p_w, t_m, w_c) || dfs(p_h, p_w + 1, t_m, w_c));
	}
	if (t_m[p_h * (w_c.width + 1) + p_w] == 'E')
		if (w_c.count == 0)
			return (1);
	return (0);
}

void	check_clearable(t_info *game_info)
{
	char			*temp_map;
	t_width_count	width_count;
	int				result;

	temp_map = ft_strdup(game_info->map);
	width_count.width = game_info->width;
	width_count.count = game_info->count_collectible;
	result = dfs(game_info->player.hei, game_info->player.wid,
			temp_map, width_count);
	free(temp_map);
	if (!result)
		print_err("Error\nUnable to Clear!");
}

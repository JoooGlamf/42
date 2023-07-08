/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:46:48 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 10:16:45 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include"mlx/mlx.h"
# include"get_next_line/get_next_line.h"
# include"ft_printf/ft_printf.h"

typedef struct s_image
{
	int		width;
	int		height;
	void	*addr;
}	t_image;

typedef struct s_images
{
	t_image	empty_space;
	t_image	wall;
	t_image	collectible;
	t_image	exit;
	t_image	player;
}	t_images;

typedef struct s_player
{
	int	wid;
	int	hei;
}	t_player;

typedef struct s_info
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			count_collectible;
	char		*map;
	t_images	images;
	t_player	player;
}	t_info;

typedef struct s_width_count
{
	int	width;
	int	count;
}	t_width_count;

void	print_err(char *message);
void	exit_game(int error);
int		x_button(int keycode, t_info *info);

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		valid_argv(char *file);
char	*read_map(t_info *game_info, char *map_name);

void	check_cpe(t_info *game_info);
void	check_rectangle(t_info *game_info);
void	check_surrounded(t_info *game_info);
void	check_letters(t_info *game_info);

char	*ft_strdup(const char *string);
int		dfs(int p_height, int p_width, char *temp_map, t_width_count w_c);
void	check_clearable(t_info *game_info);

void	get_image(t_info *game_info);
void	draw_image(t_info *game_info);

int		get_input(int keycode, t_info *game_info);
void	move_w_13(t_info *game_info);
void	move_a_0(t_info *game_info);
void	move_s_1(t_info *game_info);
void	move_d_2(t_info *game_info);

#endif
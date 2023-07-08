/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:32:54 by soojoo            #+#    #+#             */
/*   Updated: 2023/06/12 09:48:44 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	valid_argv(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	*read_map(t_info *game_info, char *map_name)
{
	int		fd;
	char	*total_line;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 2)
		print_err("Error\nmap name is wrong!");
	total_line = (char *)malloc(sizeof(char));
	total_line[0] = 0;
	line = get_next_line(fd);
	if (!line)
		print_err("Error\nmap is strange! gnl doesn't work!");
	game_info->width = ft_strlen(line) - 1;
	game_info->height = 0;
	while (line)
	{
		total_line = ft_strjoin_free(total_line, line, game_info->width + 1);
		game_info->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	return (total_line);
}

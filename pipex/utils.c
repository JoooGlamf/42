/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:16:50 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/03 11:14:20 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	**split_path(char **envp)
{
	char	*path;
	char	**output;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		++i;
	path = envp[i] + 5;
	output = ft_split(path, ':');
	if (output == 0)
		print_err("split error\n", 1);
	return (output);
}

void	print_err(char *message, int err_code)
{
	perror(message);
	exit_program(err_code);
}

void	exit_program(int err_code)
{
	if (err_code)
		exit(err_code);
	else
		exit(0);
}

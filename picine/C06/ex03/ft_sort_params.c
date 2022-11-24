/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:19:48 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/12 16:28:15 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_strcmp(char *src1, char *src2);
void	sort_argv(int argc, char **argv);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	sort_argv(argc, argv);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, argv[i] + j, 1);
		write(1, "\n", 1);
	}
}

int	ft_strcmp(char *src1, char *src2)
{
	int	i;

	i = 0;
	while (src1[i] || src2[i])
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}

void	sort_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (++i < argc - 1)
	{
		j = 0;
		while (++j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
		}
	}
}

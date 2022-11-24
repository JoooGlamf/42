/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:06:54 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/15 04:55:18 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_stock_str.h"

int		ft_strlens(char *str);
char	*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;

	p = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (p == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		p[i].size = ft_strlens(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		i++;
	}
	p[i].str = 0;
	return (p);
}

int	ft_strlens(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p_char;
	int		src_len;
	int		i;

	src_len = ft_strlens(src);
	p_char = (char *)malloc(sizeof(char) * src_len + 1);
	if (p_char == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		p_char[i] = src[i];
		i++;
	}
	p_char[src_len] = '\0';
	return (p_char);
}

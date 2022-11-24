/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:51:57 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/04 16:00:03 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	to_find_len;

	to_find_len = 0;
	while (to_find[to_find_len])
		to_find_len++;
	if (to_find_len == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
				j++;
		if (j == to_find_len)
			return (str + i);
		i++;
	}
	return ((char *) NULL);
}

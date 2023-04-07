/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:47:03 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/10 01:16:06 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	check_start(char const *s1, char const *set, size_t start)
{
	size_t	i;

	while (s1[++start])
	{
		i = -1;
		while (set[++i])
			if (s1[start] == set[i])
				break ;
		if (i >= ft_strlen(set))
			break ;
	}
	return (start);
}

size_t	check_end(char const *s1, char const *set, size_t end)
{
	size_t	i;

	while (s1[--end])
	{
		i = -1;
		while (set[++i])
			if (s1[end] == set[i])
				break ;
		if (i >= ft_strlen(set))
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1[0] == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	start = -1;
	start = check_start(s1, set, start);
	end = ft_strlen(s1);
	end = check_end(s1, set, end);
	return (ft_substr(s1, start, end - start + 1));
}

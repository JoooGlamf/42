/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:04:38 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/17 02:26:48 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	str_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			++count;
	}
	return (count);
}

size_t	char_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		++i;
	while (s[i] != c && s[i] != 0)
	{
		++i;
		++count;
	}
	++count;
	return (count);
}

size_t	alloc(char const *s, char c, char *outputs)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] == c)
		++i;
	j = 0;
	while (s[i] != c && s[i] != 0)
	{
		outputs[j] = s[i];
		++i;
		++j;
	}
	outputs[j] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	string_count;
	size_t	store_count;
	size_t	i;

	string_count = str_count(s, c);
	output = ft_calloc((int)str_count(s, c) + 1, sizeof(char *));
	if (!output)
		return (0);
	store_count = 0;
	i = -1;
	while (++i < string_count)
	{
		output[i] = (char *)malloc(sizeof(char)
				* char_count(s + store_count, c));
		if (!output[i])
		{
			while (i + 1)
				free(output[--i + 1]);
			free(output);
			return (0);
		}
		store_count += alloc(s + store_count, c, output[i]);
	}
	return (output);
}

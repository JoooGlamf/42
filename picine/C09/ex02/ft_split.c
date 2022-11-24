/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:48:34 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/14 18:31:44 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		check(char ch, char *charset);
int		count_str(char *str, char *charset);
void	fill_str(char *dest, char *src, char *charset);
void	fill_strs(char **strs, char *str, char *charset, int i);

char	**ft_split(char *str, char *charset)
{
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (count_str(str, charset) + 1));
	if (strs == 0)
		return (0);
	strs[count_str(str, charset)] = 0;
	fill_strs(strs, str, charset, -1);
	return (strs);
}

int	check(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	count_str;
	int	i;

	count_str = 0;
	i = 0;
	while (str[i])
	{
		if (check(str[i], charset) == 0 && check(str[i + 1], charset) == 1)
			count_str++;
		i++;
	}
	if (check(str[i - 1], charset) == 0 && !str[i])
		count_str++;
	return (count_str);
}

void	fill_str(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (check(src[i], charset) == 0 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	fill_strs(char **strs, char *str, char *charset, int i)
{
	int	str_len;
	int	strs_i;
	int	ex_str_len;

	str_len = 0;
	strs_i = -1;
	ex_str_len = 0;
	while (str[++i])
	{
		if (check(str[i], charset) == 0
			&& (check(str[i + 1], charset) == 1 || !str[i + 1]))
		{
			str_len++;
			strs[++strs_i] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (strs[strs_i] == 0)
				return ;
			fill_str(strs[strs_i], str + ex_str_len, charset);
			ex_str_len += str_len;
			str_len = 0;
		}
		else if (check(str[i], charset) == 0 && check(str[i + 1], charset) == 0)
			str_len++;
		else
			ex_str_len++;
	}
}

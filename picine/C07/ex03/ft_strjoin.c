/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:18:02 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/13 23:09:04 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		ft_strlens(char *str);
void	write_str(int size, char **strs, char *sep, char *p_char);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*p_char;

	if (size == 0)
	{
		p_char = (char *)malloc(sizeof(char));
		*p_char = 0;
		return (p_char);
	}
	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlens(strs[i]);
		i++;
	}
	count = count + (size - 1) * ft_strlens(sep) + 1;
	p_char = (char *)malloc(sizeof(char) * count);
	if (p_char == 0)
		return (0);
	write_str(size, strs, sep, p_char);
	p_char[count -1] = 0;
	return (p_char);
}

int	ft_strlens(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	write_str(int size, char **strs, char *sep, char *p_char)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (++j < size)
	{
		k = -1;
		while (++k < ft_strlens(strs[j]))
			p_char[++i] = strs[j][k];
		if (j != size - 1)
		{
			k = -1;
			while (++k < ft_strlens(sep))
				p_char[++i] = sep[k];
		}
	}
}

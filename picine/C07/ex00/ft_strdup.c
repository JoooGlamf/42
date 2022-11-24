/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:44:53 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/14 18:38:25 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	char	*p_char;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
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

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

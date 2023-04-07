/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:12:35 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/05 23:39:02 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ch_p;
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		ch_p = (char *)malloc(sizeof(char));
		if (!ch_p)
			return (0);
		ch_p[0] = 0;
		return (ch_p);
	}
	count = 0;
	while (s[start + count] && count < len)
		++count;
	ch_p = (char *)malloc(sizeof(char) * (count + 1));
	if (!ch_p)
		return (0);
	i = -1;
	while (++i < count)
		ch_p[i] = s[start + i];
	ch_p[count] = 0;
	return (ch_p);
}

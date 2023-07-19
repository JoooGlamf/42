/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:52:24 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/05 00:09:11 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	t_c;
	size_t	i;

	t_c = (char)c;
	if (t_c == 0)
		return ((char *)string + ft_strlen(string));
	i = -1;
	while (string[++i])
	{
		if (string[i] == t_c)
			return ((char *)string + i);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:08:11 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/05 01:03:06 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;
	unsigned char	t_c;
	size_t			i;

	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (t_s[i] == t_c)
			return ((void *)(t_s + i));
	}
	return (0);
}

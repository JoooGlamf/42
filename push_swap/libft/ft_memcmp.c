/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:29:44 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/11 21:15:34 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	char	*t_buf1;
	char	*t_buf2;
	size_t	i;

	t_buf1 = (char *)buf1;
	t_buf2 = (char *)buf2;
	i = 0;
	while (i < count)
	{
		if (t_buf1[i] != t_buf2[i])
			return ((unsigned char)t_buf1[i] - (unsigned char)t_buf2[i]);
		++i;
	}
	return (0);
}

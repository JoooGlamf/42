/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:23:25 by soojoo            #+#    #+#             */
/*   Updated: 2023/07/19 15:54:51 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = -1;
	if (dest < src)
		while (++i < n)
			t_dest[i] = t_src[i];
	else
		while (++i < n)
			t_dest[n - 1 - i] = t_src[n - 1 - i];
	return (dest);
}

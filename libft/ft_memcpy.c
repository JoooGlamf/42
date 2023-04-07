/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:09:18 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/04 03:03:23 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	if (!src && !dest)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = -1;
	while (++i < n)
		t_dest[i] = t_src[i];
	return (dest);
}

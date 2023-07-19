/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:37:40 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/17 02:24:40 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*t_s;
	unsigned char	t_c;
	size_t			i;

	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		t_s[i] = t_c;
		++i;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:49:23 by soojoo            #+#    #+#             */
/*   Updated: 2022/12/27 22:11:32 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *string)
{
	int		count;
	char	*ch_p;
	int		i;

	count = 0;
	while (string[count])
		count++;
	ch_p = (char *)malloc(sizeof(char) * (count + 1));
	if (!ch_p)
		return (0);
	i = -1;
	while (string[++i])
		ch_p[i] = string[i];
	ch_p[i] = 0;
	return (ch_p);
}

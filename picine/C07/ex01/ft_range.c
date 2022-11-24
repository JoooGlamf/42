/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:02:53 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/14 18:42:15 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p_int;
	int	i;

	if (min >= max)
		return (0);
	p_int = (int *)malloc(sizeof(int) * (max - min));
	if (p_int == 0)
		return (0);
	i = 0;
	while (i < max - min)
	{
		p_int[i] = min + i;
		i++;
	}
	return (p_int);
}

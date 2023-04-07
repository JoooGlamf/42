/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:24:30 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/05 00:11:39 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*output;
	char	t_c;
	int		i;

	t_c = (char)c;
	output = 0;
	i = -1;
	while (string[++i])
	{
		if (string[i] == t_c)
			output = (char *)string + i;
	}
	if (t_c == 0)
		output = (char *)string + i;
	return (output);
}

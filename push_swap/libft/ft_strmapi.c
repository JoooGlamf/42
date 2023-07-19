/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:30:27 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/12 02:47:03 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	if (!f)
		return ((char *)(s));
	count = ft_strlen(s);
	output = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!output)
		return (0);
	output[count] = 0;
	i = 0;
	while (s[i])
	{
		output[i] = f(i, s[i]);
		++i;
	}
	return (output);
}

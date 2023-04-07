/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:16:39 by soojoo            #+#    #+#             */
/*   Updated: 2022/12/28 00:41:24 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = -1;
	while (s1[++i])
		++count;
	i = -1;
	while (s2[++i])
		++count;
	s3 = (char *)malloc(sizeof(char) * (count + 1));
	if (!s3)
		return (0);
	i = -1;
	j = -1;
	while (s1[++j])
		s3[++i] = s1[j];
	j = -1;
	while (s2[++j])
		s3[++i] = s2[j];
	s3[i + 1] = 0;
	return (s3);
}

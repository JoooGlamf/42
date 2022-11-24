/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_c_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:15:16 by soojoo            #+#    #+#             */
/*   Updated: 2022/11/15 10:07:08 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stddef.h>
#include<stdio.h>

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while(1)
	{
		if(s[count])
			count++;
		else
			break;
	}
	return (count);
}

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char	*t_s;
	unsigned char	t_c;
	size_t			i;

	t_s = s;
	t_c = (unsigned char)c;
	i = -1;
	while(++i < n)
		t_s[i] = t_c;
	return (s);
}

void ft_bzero(void *s, size_t n)
{
	char	*t_s = (char *)s;
	size_t	i;

	i = -1;
	while(++i < n)
		t_s[i] = 0;
}

void ft_memcpy(void *dest, const void *source, size_t num)
{
	char	*t_dest;
	char	*t_source;
	size_t	i;

	t_dest = (char *)dest;
	t_source = (char *)source;
	i = -1;
	while(++i < num)
		t_dest[i] = t_source[i];
	return (dest);
}

void ft_memmove(void *dest, const void *source, size_t num)
{
	char	*t_dest;
	char	*t_source;
	size_t	i;

	t_dest = (char *)dest;
	t_source = (char *)source;
	if(dest <= src)
	{
		i = -1;
		while(++i < num)
			t_dest[i] = t_source[i];
	}
	else
	{
		t_dest += num;
		t_source += num;
		i = num;
		while(--i > 0)
			t_dest[i] = t_source[i];
	}
	return (dest);
}

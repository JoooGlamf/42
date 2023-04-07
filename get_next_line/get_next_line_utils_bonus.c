/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:30:17 by soojoo            #+#    #+#             */
/*   Updated: 2023/02/20 19:52:19 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

void	free_storage(int fd, t_buffer *tmp, t_buffer *storage)
{
	t_buffer	*t;
	t_buffer	*tt;

	if (tmp != storage)
	{
		t = storage;
		while (t->next->fd != fd)
			t = t->next;
		tt = t->next;
		t->next = t->next->next;
		free(tt);
	}
}

long long	find_nl(char *string)
{
	long long	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strjoin_free(char *s1, char *s2, size_t s2_len)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		++i;
	s3 = (char *)malloc(sizeof(char) * (i + s2_len + 1));
	if (!s3)
	{
		free(s1);
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[j])
		s3[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = 0;
	return (s3);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	long long		i;

	if (!dest && !src)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = -1;
	if (dest < src)
		while (++i < (long long)n)
			t_dest[i] = t_src[i];
	else
		while (++i < (long long)n)
			t_dest[n - 1 - i] = t_src[n - 1 - i];
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t_s;
	size_t			i;

	t_s = (unsigned char *)s;
	i = 0;
	while (i < n)
		t_s[i++] = 0;
}

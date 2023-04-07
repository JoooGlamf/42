/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:20:41 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/11 21:13:32 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include"libft.h"
#include<stdio.h>
#include<stdlib.h>

size_t	count_count(long long n)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++count;
		n *= -1;
	}
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	t_n;
	char		*output;
	size_t		count;

	t_n = (long long)n;
	count = count_count(t_n);
	output = (char *)malloc(sizeof(char) * (count + 1));
	if (!output)
		return (0);
	output[count] = 0;
	if (t_n == 0)
		output[0] = '0';
	if (t_n < 0)
	{
		t_n *= -1;
		output[0] = '-';
	}
	while (t_n)
	{
		output[--count] = t_n % 10 + 48;
		t_n /= 10;
	}
	return (output);
}

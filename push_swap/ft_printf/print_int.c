/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:31:00 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 13:52:22 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

int	count_count(long long n)
{
	int	count;

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
	int			count;

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

int	print_int(int num)
{
	char	*output;
	int		write_output;
	int		i;

	output = ft_itoa(num);
	if (!output)
		return (-1);
	i = 0;
	while (output[i])
		++i;
	write_output = write(1, output, i);
	free(output);
	if (write_output == -1)
		return (-1);
	return (i);
}

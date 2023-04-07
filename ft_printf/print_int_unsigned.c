/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:31:00 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 13:52:23 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

int	count_ucount(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char			*output;
	int				count;

	count = count_ucount(n);
	output = (char *)malloc(sizeof(char) * (count + 1));
	if (!output)
		return (0);
	output[count] = 0;
	if (n == 0)
		output[0] = '0';
	while (n)
	{
		output[--count] = n % 10 + 48;
		n /= 10;
	}
	return (output);
}

int	print_int_unsigned(unsigned int num)
{
	char	*output;
	int		write_output;
	int		i;

	output = ft_uitoa(num);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:29:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 13:52:25 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	count_hex(unsigned int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num)
	{
		num /= 16;
		++count;
	}
	return (count);
}

char	*make_hex(char xX, unsigned int num)
{
	char	*output;
	int		count;

	count = count_hex(num);
	output = (char *)malloc(sizeof(char) * (count + 1));
	if (!output)
		return (0);
	output[count] = 0;
	if (num == 0)
		output[0] = '0';
	while (num)
	{
		if (num % 16 < 10)
			output[--count] = '0' + num % 16;
		else
		{
			if (xX == 'x')
				output[--count] = 'a' - 10 + num % 16;
			else if (xX == 'X')
				output[--count] = 'A' - 10 + num % 16;
		}
		num /= 16;
	}
	return (output);
}

int	print_hex(char xX, unsigned int num)
{
	char	*output;
	int		write_output;
	int		i;

	output = make_hex(xX, num);
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

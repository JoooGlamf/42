/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:10:06 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 10:37:11 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	print_str(char *str)
{
	int		count;
	int		write_output;

	if (str == 0)
	{
		write_output = write(1, "(null)", 6);
		if (write_output == -1)
			return (-1);
		return (6);
	}
	count = 0;
	while (str[count])
		++count;
	write_output = write(1, str, count);
	if (write_output == -1)
		return (-1);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:44:02 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 13:52:21 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	print_percent(void)
{
	char	percent;
	int		write_output;

	percent = '%';
	write_output = write(1, &percent, 1);
	if (write_output == -1)
		return (-1);
	return (1);
}

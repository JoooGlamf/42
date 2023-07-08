/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:06:17 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 10:35:13 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	print_char(char c)
{
	int	write_output;

	write_output = write(1, &c, 1);
	if (write_output == -1)
		return (-1);
	return (1);
}

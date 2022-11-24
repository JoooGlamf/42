/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:27:44 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/07 14:35:18 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	make_hex_arr(char *hex_arr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			hex_arr[i] = '0' + i;
		else
			hex_arr[i] = 'a' + i - 10;
		i++;
	}
}

void	make_char_hex(char *str, int *hex_num, char *hex_arr, int i)
{
	if (!(str[i] >= 32 && str[i] <= 126))
	{
		hex_num[0] = (unsigned char)str[i] / 16;
		hex_num[1] = (unsigned char)str[i] % 16;
		write(1, "\\", 1);
		if (hex_num[0] > 0)
		{
			write(1, hex_arr + hex_num[0], 1);
			write(1, hex_arr + hex_num[1], 1);
		}	
		else
		{
			write(1, "0", 1);
			write(1, hex_arr + hex_num[1], 1);
		}
	}
	else
		write(1, str + i, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	hex_arr[20];
	int		hex_num[2];
	int		i;

	make_hex_arr(hex_arr);
	i = 0;
	while (str[i])
	{
		make_char_hex(str, hex_num, hex_arr, i);
		i++;
	}
}

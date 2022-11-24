/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:40:07 by soojoo            #+#    #+#             */
/*   Updated: 2022/08/31 12:05:29 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	recur(char *arr, int value, int index, int n);

void	ft_print_combn(int n)
{
	char	arr[10];

	recur(arr, 0, 0, n);
}

void	recur(char *arr, int index, int value, int n)
{
	while (value <= 10 - n + index)
	{	
		arr[index] = '0' + value;
		if (index == n - 1)
		{
			write(1, arr, n);
			if (arr[0] != '0' + 10 - n)
				write(1, ", ", 2);
		}
		else
		{			
			recur(arr, index + 1, value + 1, n);
		}
		value++;
	}
}

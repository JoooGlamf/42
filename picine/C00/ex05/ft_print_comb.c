/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:05:10 by soojoo            #+#    #+#             */
/*   Updated: 2022/08/31 19:32:47 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void);

void	ft_print_comma(char a, char b, char c);

void	ft_print_comb(void)
{	
	char	numbers[3];

	numbers[0] = '0';
	numbers[1] = '0';
	numbers[2] = '0';
	while (numbers[0] < '8')
	{
		while (numbers[1] <= numbers[0] && numbers[1] < '8')
			numbers[1]++;
		while (numbers[2] < numbers[1] && numbers[2] < '9')
			numbers[2]++;
		if (numbers[2] < '9')
			numbers[2]++;
		write(1, numbers, 3);
		ft_print_comma(numbers[0], numbers[1], numbers[2]);
		if (numbers[1] == '8' && numbers[2] == '9' && numbers[0])
			numbers[0]++;
		if (numbers[2] == '9')
		{
			numbers[2] = '0';
			numbers[1]++;
		}
		if (numbers[1] == '9')
			numbers[1] = '0';
	}
}

void	ft_print_comma(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
		;
	else
		write(1, ", ", 2);
}	

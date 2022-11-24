/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:15:12 by soojoo            #+#    #+#             */
/*   Updated: 2022/08/31 19:38:24 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb2(void);

void	print_answer(char *f_num, char *b_num);

void	over_nine(char *number);

void	ft_print_comb2(void)
{
	char	front_num[2];
	char	back_num[2];

	front_num[0] = '0';
	front_num[1] = '0';
	back_num[0] = '0';
	back_num[1] = '1';
	while (front_num[0] <= '9' && front_num[1] <= '8')
	{
		while (back_num[0] <= '9' && back_num[1] <= '9')
		{
			print_answer(front_num, back_num);
			back_num[1]++;
			over_nine(back_num);
			if (back_num[0] > '9')
			{
				front_num[1]++;
				over_nine(front_num);
				back_num[1] = front_num[1] + 1;
				back_num[0] = front_num[0];
				over_nine(back_num);
			}
		}
	}
}

void	print_answer(char *f_num, char *b_num)
{
	write(1, f_num, 2);
	write(1, " ", 1);
	write(1, b_num, 2);
	if (!(f_num[0] == '9' && f_num[1] == '8'))
		write(1, ", ", 2);
}

void	over_nine(char *number)
{
	if (number[1] > '9')
	{
		number[1] = '0';
		number[0]++;
	}	
}

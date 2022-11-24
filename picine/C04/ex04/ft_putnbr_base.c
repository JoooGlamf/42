/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:46:18 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/09 21:05:09 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		baselen(char *base);
int		exception(char *base, int base_len);
void	print_number(char *base, int *int_array, int i);

void	ft_putnbr_base(int nbr, char *base)
{
	long long	number;
	int			base_len;
	int			int_array[32];
	int			i;

	number = (long long)nbr;
	base_len = baselen(base);
	if (exception(base, base_len) == 0)
		return ;
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (number == 0)
		write(1, base, 1);
	i = 0;
	while (number)
	{
		int_array[i] = number % base_len;
		number /= base_len;
		i++;
	}
	print_number(base, int_array, i);
}

int	baselen(char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		count++;
	}
	return (count);
}

int	exception(char *base, int base_len)
{
	int	i;
	int	j;
	int	count_same;

	if (base_len <= 1)
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		count_same = 0;
		j = 0 ;
		while (j < base_len)
		{
			if (base[i] == base[j])
				count_same++;
			j++;
		}
		if (count_same > 1)
			return (0);
		i++;
	}
	return (1);
}

void	print_number(char *base, int *int_array, int i)
{
	while (i)
	{
		write(1, base + int_array[i - 1], 1);
		i--;
	}
}

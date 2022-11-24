/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:12:53 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/09 19:24:29 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	int_len(int nb);

void	ft_putnbr(int nb)
{
	long long	number;
	char		number_char[20];
	int			len;
	int			i;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	number = (long long)nb;
	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	len += int_len(nb);
	i = -1;
	while (++i < len)
	{
		number_char[len - 1 - i] = number % 10 + '0';
		number /= 10;
	}
	write(1, number_char, len);
}

int	int_len(int nb)
{
	int	count;

	count = 0;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

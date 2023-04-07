/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:59:50 by soojoo            #+#    #+#             */
/*   Updated: 2023/01/06 00:39:48 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

void	ft_putnbr_fd(int nb, int fd)
{
	long long	number;
	char		number_char[20];
	int			len;
	int			i;

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number = (long long)nb;
	len = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	len += int_len(nb);
	i = -1;
	while (++i < len)
	{
		number_char[len - 1 - i] = number % 10 + '0';
		number /= 10;
	}
	write(fd, number_char, len);
}

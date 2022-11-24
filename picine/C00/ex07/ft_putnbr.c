/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:31:03 by soojoo            #+#    #+#             */
/*   Updated: 2022/08/31 23:20:38 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb);

int		ft_intlen(int nb);

int		ft_calculate_number(int nb, int len);

int		ft_power_10(int len);

void	ft_write_number(int nb);

void	ft_putnbr(int nb)
{
	char		minus;

	minus = '-';
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb > 0)
		ft_write_number(nb);
	if (nb < 0)
	{
		write(1, &minus, 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		else
		{
			nb *= -1;
			ft_write_number(nb);
		}
	}
}

int	ft_intlen(int nb)
{
	int	count;

	count = 0;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_calculate_number(int nb, int len)
{
	int	power_10;

	power_10 = ft_power_10(len);
	nb = nb / power_10;
	return (nb);
}

int	ft_power_10(int len)
{
	int	power_10;

	power_10 = 1;
	while (len - 1 > 0)
	{
		power_10 *= 10;
		len--;
	}
	return (power_10);
}

void	ft_write_number(int nb)
{
	int		len;
	char	write_number;

	len = ft_intlen(nb);
	while (len > 0)
	{
		if (len == 1)
		{
			write_number = '0' + nb;
			write(1, &write_number, 1);
		}
		else
		{
			write_number = '0' + ft_calculate_number(nb, len);
			nb = nb % ft_power_10(len);
			write(1, &write_number, 1);
		}
		len--;
	}
}

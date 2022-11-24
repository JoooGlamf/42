/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:37:56 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/15 04:39:30 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ft_stock_str.h"

void	ft_print_str(char *str);
void	ft_putnbr(int nb);
int		int_len(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_print_str(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_print_str(par[i].copy);
		write(1, "\n", 1);
		par++;
	}
}

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

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

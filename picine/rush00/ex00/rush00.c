/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhong <chanhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:30:18 by chanhong          #+#    #+#             */
/*   Updated: 2022/08/28 19:05:26 by chanhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	first(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('o');
		else if (i + 1 < x)
			ft_putchar('-');
		else
			ft_putchar('o');
		i++;
	}
}

void	middle(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	while (j <= y - 2)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0)
				ft_putchar('|');
			else if (i + 1 < x)
				ft_putchar(' ');
			else
				ft_putchar('|');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	last(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('o');
		else if (i + 1 < x)
			ft_putchar('-');
		else
			ft_putchar('o');
		i++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		first(x);
		ft_putchar('\n');
		middle(x, y);
		if (y >= 2)
		{
			last(x);
			ft_putchar('\n');
		}
	}
}

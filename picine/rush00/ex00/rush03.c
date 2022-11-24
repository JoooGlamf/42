/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhong <chanhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:42:07 by chanhong          #+#    #+#             */
/*   Updated: 2022/08/28 19:07:37 by chanhong         ###   ########.fr       */
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
			ft_putchar('A');
		else if (i + 1 < x)
			ft_putchar('B');
		else
			ft_putchar('C');
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
				ft_putchar('B');
			else if (i + 1 < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
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
			ft_putchar('A');
		else if (i + 1 < x)
			ft_putchar('B');
		else
			ft_putchar('C');
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

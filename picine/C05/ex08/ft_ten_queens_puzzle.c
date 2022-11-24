/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:40:47 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/11 16:00:25 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	arrange_queens(int *queens, int *count, int row);
int		valid_check(int *queens, int row);
void	print_queens(int *queens);

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	*p_count;
	int	i_count;
	int	i;

	i = 0;
	while (queens[i])
	{
		queens[i] = '\0';
		i++;
	}
	i_count = 0;
	p_count = &i_count;
	arrange_queens(queens, p_count, 0);
	return (i_count);
}

void	arrange_queens(int *queens, int *count, int row)
{
	int	col;

	if (row == 10)
	{
		print_queens(queens);
		(*count)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{	
		queens[row] = col;
		if (valid_check(queens, row))
		{
			arrange_queens(queens, count, row + 1);
		}
		col++;
	}
}

int	valid_check(int *queens, int row)
{
	int	before_row;

	before_row = 0;
	while (before_row < row)
	{
		if (queens[before_row] == queens[row]
			|| queens[before_row] + row - before_row == queens[row]
			|| queens[before_row] - (row - before_row) == queens[row])
			return (0);
		before_row++;
	}
	return (1);
}

void	print_queens(int *queens)
{
	int		i;
	char	number;

	i = 0;
	while (i < 10)
	{
		number = '0' + queens[i];
		write(1, &number, 1);
		i++;
	}
	write(1, "\n", 1);
}

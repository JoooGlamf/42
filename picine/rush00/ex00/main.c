/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhong <chanhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:33:41 by chanhong          #+#    #+#             */
/*   Updated: 2022/08/28 20:54:49 by chanhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	char_to_int(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ac == 3)
	{
		x = char_to_int(av[1]);
		y = char_to_int(av[2]);
	}
	rush(x, y);
	return (0);
}

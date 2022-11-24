/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:57:56 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/09 19:27:31 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	str_int;

	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	str_int = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		str_int = str_int * 10 + str[i] - '0';
		i++;
	}
	if (count % 2 == 1)
		str_int *= -1;
	return (str_int);
}

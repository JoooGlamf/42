/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:48:10 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/14 20:22:07 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen2(char *str);
int			str_in_base(char str, char *base);
long long	make_decimal(char *str, char *base, int i);
int			ft_atoi_base(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	long long	number;
	int			base_len;
	int			i;
	int			count_minus;

	base_len = ft_strlen2(base);
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	count_minus = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count_minus++;
		i++;
	}
	number = make_decimal(str, base, i);
	if (count_minus % 2 == 1)
		number *= -1;
	return ((int)number);
}

int	ft_strlen2(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	str_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (i < ft_strlen2(base))
	{
		if (str == base[i])
			return (1);
		i++;
	}
	return (0);
}

long long	make_decimal(char *str, char *base, int i)
{
	long long	number;
	int			base_len;
	int			j;

	base_len = ft_strlen2(base);
	number = 0;
	while (str_in_base(str[i], base))
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				number = number * base_len + j;
			j++;
		}
		i++;
	}
	return (number);
}

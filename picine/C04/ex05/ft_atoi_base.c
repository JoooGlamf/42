/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:05:29 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/10 14:34:45 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen2(char *str);
int			str_in_base(char str, char *base);
int			exceptions(char *base, int baselen);
long long	make_decimal(char *str, char *base, int i);

int	ft_atoi_base(char *str, char *base)
{
	long long	number;
	int			base_len;
	int			i;
	int			count_minus;

	base_len = ft_strlen2(base);
	if (exceptions(base, base_len) == 0)
		return (0);
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

int	exceptions(char *base, int base_len)
{
	int	i;
	int	j;
	int	count_same;

	if (base_len <= 1)
		return (0);
	i = -1;
	while (++i < base_len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		count_same = 0;
		j = -1;
		while (++j < base_len)
		{
			if (base[i] == base[j])
				count_same++;
		}
		if (count_same > 1)
			return (0);
	}
	return (1);
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

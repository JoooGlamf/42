/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:47:45 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/14 17:55:23 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		exceptions(char *base, int base_len);
int		baselen(char *base);
void	ft_putnbr_base(int nbr, char *base, char *output, int output_length);
int		cal_len(int num, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_num;
	int		output_length;
	char	*output;

	if (exceptions(base_from, baselen(base_from)) == 0)
		return (0);
	if (exceptions(base_to, baselen(base_to)) == 0)
		return (0);
	int_num = ft_atoi_base(nbr, base_from);
	output_length = cal_len(int_num, base_to);
	output = (char *)malloc(sizeof(char) * output_length + 1);
	if (output == 0)
		return (0);
	ft_putnbr_base(int_num, base_to, output, output_length);
	return (output);
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

int	cal_len(int num, char *base)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num)
	{
		num /= baselen(base);
		count++;
	}
	return (count);
}

void	ft_putnbr_base(int nbr, char *base, char *output, int output_length)
{
	long long	number;
	int			base_len;
	int			i;

	number = (long long)nbr;
	base_len = baselen(base);
	if (number == 0)
	{
		output[0] = base[0];
		output[1] = '\0';
		return ;
	}
	if (number < 0)
	{
		number *= -1;
		output[0] = '-';
	}
	i = output_length - 1;
	while (number)
	{
		output[i] = base[number % base_len];
		number /= base_len;
		i--;
	}
	output[output_length] = '\0';
}

int	baselen(char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		count++;
	}
	return (count);
}

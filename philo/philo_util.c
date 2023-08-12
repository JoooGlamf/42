/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:18:09 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 15:14:28 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long long	get_current_time()
{
	struct timeval	time;
	int				current_time;

	gettimeofday(&time, NULL);
	current_time = time.tv_usec / 1000;
	return (current_time);
}

long long	get_running_time(int start_time)
{
	struct timeval	current_time;
	int				running_time;

	gettimeofday(&current_time, NULL);
	running_time = current_time.tv_usec / 1000 - start_time;
	return (running_time);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	str_int;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		++i;
	if (str[i] == '-')
	{	
		minus *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	str_int = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		str_int = str_int * 10 + str[i] - '0';
		i++;
	}
	str_int *= minus;
	return (str_int);
}

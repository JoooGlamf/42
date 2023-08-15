/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:08:08 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 03:24:13 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long long	convert_time_ms(struct timeval time)
{
	int	ms;

	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

long long	get_current_time_ms()
{
	struct timeval	current_time;
	long long		current_time_ms;

	gettimeofday(&current_time, NULL);
	current_time_ms = convert_time_ms(current_time);
	return (current_time_ms);
}

long long	get_running_time_ms(long long init_time_ms)
{
	long long	current_time_ms;
	long long	running_time_ms;

	current_time_ms = get_current_time_ms();
	running_time_ms = current_time_ms - init_time_ms;
	return (running_time_ms);
}

int	exact_sleep(long long sleep_time)
{
	long long	start_time;

	start_time = get_current_time_ms();
	while(start_time + sleep_time > get_current_time_ms())
	{
		usleep(10);
	}
	return (0);
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

int	locked_printf(pthread_mutex_t *mutex, long long init_time, int philo_num, char *status)
{
	int			output;
	long long	running_time;

	pthread_mutex_lock(mutex);
	running_time = get_running_time_ms(init_time);
	output = printf("%lld_in_ms %d %s\n", running_time, philo_num, status);
	pthread_mutex_unlock(mutex);
	return (output);
}

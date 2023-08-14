/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:57:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/15 00:47:13 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*actions(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	if(data->argv->number_of_must_eat == -1)
	{
		while(1)
		{
			think_action(data);
			if(data->philo_num % 2)
				eat_action_odd(data);
			else
				eat_action_even(data);
			sleep_action(data);
		}
	}
	else
	{
		while(data->numbers_eat < data->argv->number_of_must_eat)
		{
			think_action(data);
			if(data->philo_num % 2)
				eat_action_odd(data);
			else
				eat_action_even(data);
			sleep_action(data);
		}
	}
	return (0);
}

void	think_action(t_data *data)
{
	data->running_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "is thinking");
}

void	eat_action_odd(t_data *data)
{
	pthread_mutex_lock(data->mutexes->forks + data->philo_num);
	pthread_mutex_lock(data->mutexes->forks + (data->philo_num + 1) % data->argv->num_of_philo);
	data->running_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "has taken a fork");
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "is eating");
	exact_sleep(data->argv->time_to_eat);
	data->running_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	data->last_eat_time = data->running_time;
	data->numbers_eat += 1;
	pthread_mutex_unlock(data->mutexes->forks + data->philo_num);
	pthread_mutex_unlock(data->mutexes->forks + (data->philo_num + 1) % data->argv->num_of_philo);
}

void	eat_action_even(t_data *data)
{
	exact_sleep(1);
	pthread_mutex_lock(data->mutexes->forks + (data->philo_num + 1) % data->argv->num_of_philo);
	pthread_mutex_lock(data->mutexes->forks + data->philo_num);
	data->running_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "has taken a fork");
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "is eating");
	exact_sleep(data->argv->time_to_eat);
	data->last_eat_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	data->numbers_eat += 1;
	pthread_mutex_unlock(data->mutexes->forks + (data->philo_num + 1) % data->argv->num_of_philo);
	pthread_mutex_unlock(data->mutexes->forks + data->philo_num);
}

void	sleep_action(t_data *data)
{
	data->running_time = get_running_time_ms(data->mutexes->time_mutex, data->init_time);
	locked_printf(data->mutexes->print_mutex, data->running_time, data->philo_num, "is sleeping");
	exact_sleep(data->argv->time_to_sleep);
}

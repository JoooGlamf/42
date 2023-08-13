/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:57:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/13 18:02:46 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*actions(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if(philo->info->number_of_must_eat == -1)
	{
		while(1)
		{
			eat_philo(philo);
			sleep_philo(philo);
			think_philo(philo);
		}
	}
	else
	{
		while(philo->numbers_eat < philo->info->number_of_must_eat)
		{
			eat_philo(philo);
			sleep_philo(philo);
			think_philo(philo);
		}
	}
	return (0);
}

int	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld_in_ms %d has taken a fork\n", get_running_time_ms(philo->info->init_time), philo->philo_num);
	*(philo->left_fork) = 0;
	*(philo->right_fork) = 0;
	printf("%lld_in_ms %d is eating\n", get_running_time_ms(philo->info->init_time), philo->philo_num);
	usleep(1000 * philo->info->time_to_eat);
	*(philo->left_fork) = 1;
	*(philo->right_fork) = 1;
	philo->numbers_eat += 1;
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

int	think_philo(t_philo *philo)
{
	printf("%lld_in_ms %d is thinking\n", get_running_time_ms(philo->info->init_time), philo->philo_num);
	usleep(1000 * philo->info->time_to_eat);
	return (0);
}

int sleep_philo(t_philo *philo)
{
	printf("%lld_in_ms %d is sleeping\n", get_current_time_ms(philo->info->init_time), philo->philo_num);
	usleep(1000 * philo->info->time_to_sleep);
	return (0);
}

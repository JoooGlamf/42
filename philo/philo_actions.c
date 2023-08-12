/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:57:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/12 21:09:15 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*actions(void *void_philo)
{
	t_philo	*philo;

	usleep(1000 * 10);
	philo = (t_philo *)void_philo;
//	if(philo-info->number_of_must_eat == -1)
//	{
//		while(1)
//		{
//		
//		}
//	}
//	else
//	{
//		while(philo->numbers_eat < philo->info->number_of_must_eat)
//		{
//		
//		}
//	}
	pthread_mutex_lock(philo->mutex);
	printf("name: %d\n", (int)philo->tid);
	pthread_mutex_unlock(philo->mutex);
	return (0);
	//철학자가 먹고 있다고 출력	
	//몇 밀리세컨드동안 먹어야하는데 어떻게?
	//먹은 뒤 수면
	//깨어나면 생각, 생각하다가 숫가락 비면 먹어야되는데;;
}

//int	eat(t_philo *philo)
//{
//	if(*(philo->left_fork) != 0 && *(philo->right_fork) != 0)
//	{
//		pthread_mutex_lock(philo->mutex);
//		philo->last_eaten_time = get_running_time(philo->info->init_time);
//		printf("%lld_in_ms %lld	has eating\n");
//		usleep(1000 * philo->info->time_to_eat);
//	}
//}
//
//int	think(t_philo *philo)
//{
//	
//}
//
//int sleep(t_philo *philo)
//{
//	printf("%lld_in_ms %lld is sleeping\n");
//	usleep(1000 * philo->info->time_to_sleep);
//}

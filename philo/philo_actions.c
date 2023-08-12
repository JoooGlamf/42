/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:57:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 18:07:39 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*actions(void *philo)
{
	t_philo	*converted_philo;

	converted_philo = (t_philo *)philo;
	pthread_mutex_lock(converted_philo->mutex);
	printf("name: %lld\n", (long long)converted_philo->tid);
	pthread_mutex_unlock(converted_philo->mutex);
	return (0);
	//철학자가 먹고 있다고 출력	
	//몇 밀리세컨드동안 먹어야하는데 어떻게?
	//먹은 뒤 수면
	//깨어나면 생각, 생각하다가 숫가락 비면 먹어야되는데;;
}

int	eat(t_philo *philo)
{
	if(*(philo->left_fork) == 1 &&
}

int sleep(t_philo *philo)
{
	printf("");
	usleep(1000 * 1000
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:57:04 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 12:51:11 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	actions(void *data)
{
	pthread_mutex_t	*mutex;

	pthread_mutex_init(mutex, NULL);
	pthread_mutex_lock(mutex);
	printf("");
	pthread_mutex_unlock(mutex);
	pthread_mutex_destroy(mutex);
	//철학자가 먹고 있다고 출력	
	//몇 밀리세컨드동안 먹어야하는데 어떻게?
	//먹은 뒤 수면
	//깨어나면 생각, 생각하다가 숫가락 비면 먹어야되는데;;
}

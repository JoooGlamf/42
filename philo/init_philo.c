/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:34 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/12 20:56:53 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_info	*set_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		info->number_of_must_eat = ft_atoi(argv[5]);
	else
		info->number_of_must_eat = -1;
	info->init_time = get_current_time_ms();
	return (info);
}

int	*set_forks(t_info *info)
{
	int	*forks;
	int	i;

	forks = (int *)malloc(sizeof(int) * info->num_of_philo);
	i = 0;
	while(i < info->num_of_philo)
	{
		forks[i] = 1;
		++i;
	}
	return (forks);
}

t_philo	*init_philos(t_info *info, int *forks)
{
	t_philo			*philos;
	pthread_mutex_t	mutex;
	int				i;

	pthread_mutex_init(&mutex, NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo); 
	i = 0;
	while(i < info->num_of_philo)
	{
		(philos + i)->mutex = &mutex;
		(philos + i)->info = info;
		(philos + i)->left_fork = forks + i;
		(philos + i)->right_fork = forks + (i + 1) % info->num_of_philo;
		(philos + i)->numbers_eat = 0;
		(philos + i)->last_eat_time = 0;
		pthread_create(&((philos + i)->tid), NULL, actions, (philos + i));
		++i;
	}
	return (philos);
}

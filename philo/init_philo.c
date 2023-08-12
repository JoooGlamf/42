/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:34 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 17:30:09 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_info	*init_info(int argc, char **argv)
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
	info->init_time = get_current_time();
	return (info);
}

int	*init_forks(t_info *info)
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

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	pthread_mutex_t	mutex;
	int		i;

	pthread_mutex_init(&mutex, NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * data->info->num_of_philo); 
	i = 0;
	while(i < data->info->num_of_philo)
	{
		pthread_create(&((philos + i)->tid), NULL, actions, (philos + i));
		(philos + i)->left_fork = data->forks + i;
		(philos + i)->right_fork = data->forks + (i + 1) % data->info->num_of_philo;
		(philos + i)->numbers_eat = 0;
		(philos + i)->mutex = &mutex;
		++i;
	}
	return (philos);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->info = init_info(argc, argv);
	data->philos = init_philos(data);
	data->forks = init_forks(data->info);
	return (data);
}

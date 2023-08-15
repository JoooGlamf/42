/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:34 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 00:55:00 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_argv	*init_argv(int argc, char **argv)
{
	t_argv	*structed_argv;
	
	structed_argv = (t_argv *)malloc(sizeof(t_argv));
	structed_argv->num_of_philo = ft_atoi(argv[1]);
	structed_argv->time_to_die = ft_atoi(argv[2]);
	structed_argv->time_to_eat = ft_atoi(argv[3]);
	structed_argv->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		structed_argv->number_of_must_eat = ft_atoi(argv[5]);
	else
		structed_argv->number_of_must_eat = -1;
	return (structed_argv);
}

t_mutexes	*init_mutexes(t_argv *argv)
{
	t_mutexes	*mutexes;
	int			i;

	mutexes = (t_mutexes *)malloc(sizeof(t_mutexes));
	mutexes->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argv->num_of_philo);
	mutexes->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexes->died_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexes->last_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argv->num_of_philo);
	i = 0;
	while(i < argv->num_of_philo)
	{
		pthread_mutex_init(mutexes->forks + i, NULL);
		pthread_mutex_init(mutexes->last_eat_mutex + i, NULL);
		++i;
	}
	pthread_mutex_init(mutexes->print_mutex, NULL);
	pthread_mutex_init(mutexes->died_mutex, NULL);
	return (mutexes);
}

t_data	*init_data(int argc, char **argv)
{
	t_data		*data;
	t_argv		*structed_argv;
	t_mutexes	*mutexes;
	int			*died;
	int			i;

	structed_argv = init_argv(argc, argv);
	mutexes = init_mutexes(structed_argv);
	died = (int *)malloc(sizeof(int));
	*died = 0;
	data = (t_data *)malloc(sizeof(t_data) * structed_argv->num_of_philo);
	i = 0;
	while(i < structed_argv->num_of_philo)
	{
		(data + i)->argv = structed_argv;
		(data + i)->mutexes = mutexes;
		(data + i)->numbers_eat = 0;
		(data + i)->last_eat_time = 0;
		(data + i)->died = died;
		++i;
	}
	return (data);
}

pthread_t	*init_philos(t_data *data)
{
	pthread_t	*philos;
	long long	init_time;
	int			i;

	philos = (pthread_t *)malloc(sizeof(pthread_t) * data->argv->num_of_philo);
	i = 0;
	init_time = get_current_time_ms();
	while(i < data->argv->num_of_philo)
	{
		(data + i)->philo_num = i;
		(data + i)->init_time = init_time;
		pthread_create(philos + i, NULL, actions, (void *)(data + i));
		++i;
	}
	return (philos);
}

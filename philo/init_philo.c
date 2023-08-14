/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:34 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/14 04:50:33 by soojoo           ###   ########.fr       */
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

int	*init_forks(t_argv *argv)
{
	int	*forks;
	int	i;

	forks = (int *)malloc(sizeof(int) * argv->num_of_philo);
	i = 0;
	while(i < argv->num_of_philo)
	{
		forks[i] = 1;
		++i;
	}
	return (forks);
}

pthread_mutex_t	*init_mutexes(t_argv *argv)
{
	pthread_mutex_t	*mutexes;
	int				i;

	mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argv->num_of_philo);
	i = 0;
	while(i < argv->num_of_philo)
	{
		pthread_mutex_init(mutexes + i, NULL);
		++i;
	}
	return (mutexes);
}

t_data	*init_datas(int argc, char **argv)
{
	t_data	*datas;
	t_argv	*structed_argv;
	pthread_mutex_t	*mutexes;
	int		*forks;
	int		i;

	structed_argv = init_argv(argc, argv);
	forks = init_forks(structed_argv);
	mutexes = init_mutexes(structed_argv);
	datas = (t_data *)malloc(sizeof(t_data) * structed_argv->num_of_philo);
	i = 0;
	while(i < structed_argv->num_of_philo)
	{
		(datas + i)->argv = structed_argv;
		(datas + i)->mutexes = mutexes;
		(datas + i)->philo_num = i;
		(datas + i)->forks = forks;
		//(datas + i)->left_fork = forks + i;
		//(datas + i)->right_fork = forks + (i + 1) % info->num_of_philo;
		(datas + i)->init_time = 0;
		(datas + i)->last_eat_time = 0;
		++i;
	}
	return (datas);
}

pthread_t	*init_philos(t_data *datas)
{
	pthread_t	*philos;
	int				i;

	philos = (pthread_t *)malloc(sizeof(pthread_t) * datas->argv->num_of_philo);
	i = 0;
	while(i < datas->argv->num_of_philo)
	{
		pthread_create(philos + i, NULL, actions, (void *)(datas + i));
		++i;
	}
	return (philos);
}

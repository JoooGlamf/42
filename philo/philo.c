/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/14 22:26:39 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	return_error(int code, char *message)
{
	printf("%s\n", message);
	return (code);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	if(argc != 5 && argc != 6)
		return (1);
	i  = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
			{
				return (1);
			}	
			++j;
		}
		++i;
	}
	return (0);
}

int	end_philos(t_data *datas, pthread_t *philos)
{
	int	num_of_philo;
	int	i;

	num_of_philo = datas->argv->num_of_philo;
	i = 0;
	while(i < num_of_philo)
	{
		pthread_join(philos[i], NULL);
		++i;
	}
	i = 0;
	while(i < num_of_philo)
	{
		pthread_mutex_destroy(datas->mutexes->forks + i);
		++i;
	}
	pthread_mutex_destroy(datas->mutexes->print_mutex);
	pthread_mutex_destroy(datas->mutexes->print_mutex);
	free(philos);
	free(datas->argv);
	free(datas->mutexes->forks);
	free(datas->mutexes->print_mutex);
	free(datas->mutexes->time_mutex);
	free(datas->mutexes);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t		*philos;
	t_data			*data;

	if(check_argv(argc, argv))
		return (return_error(-1, "arguments error!"));
	data = init_data(argc, argv);
	philos = init_philos(data);
	end_philos(data, philos);
}

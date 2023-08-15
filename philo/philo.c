/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/16 04:05:21 by soojoo           ###   ########.fr       */
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

int	check_died(t_data *data)
{
	long long	running_time;
	int			i;

	while(1)
	{
		pthread_mutex_lock(data->mutexes->died_mutex);
		if(*data->died)
		{
			pthread_mutex_unlock(data->mutexes->died_mutex);
			break;
		}
		pthread_mutex_unlock(data->mutexes->died_mutex);
		i = 0;
		while(i < data->argv->num_of_philo)
		{
			running_time = get_running_time_ms(data->init_time);
			pthread_mutex_lock(data->mutexes->last_eat_mutex + i);
			if(running_time - (data + i)->last_eat_time >= data->argv->time_to_die)
			{
				pthread_mutex_unlock(data->mutexes->last_eat_mutex + i);
				pthread_mutex_lock(data->mutexes->died_mutex);
				*(data->died) = 1;
				pthread_mutex_unlock(data->mutexes->died_mutex);
				locked_printf(data->mutexes->print_mutex, data->init_time, (data + i)->philo_num, "is died");

				break;
			}
			pthread_mutex_unlock(data->mutexes->last_eat_mutex + i);
			++i;
		}
	i = 0;
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
	check_died(data);
	end_philos(data, philos);
}

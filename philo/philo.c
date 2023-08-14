/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/14 04:46:59 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	return_error(int code, char *message)
{
	printf("%s", message);
	return (code);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	if(argc != 5 && argc != 6)
		return (0);
	i  = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
			{
				return (0);
			}	
			++j;
		}
		++i;
	}
	return (1);
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
		pthread_mutex_destroy(datas->mutexes + i);
		++i;
	}
	free(philos);
	free(datas->argv);
	free(datas->mutexes);
	free(datas->forks);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t		*philos;
	t_data			*datas;

	datas = init_datas(argc, argv);
	philos = init_philos(datas);
	end_philos(datas, philos);
}

	

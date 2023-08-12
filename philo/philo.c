/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/12 20:57:32 by soojoo           ###   ########.fr       */
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

int	end_philo(t_info *info, t_philo *philos)
{
	int	i;
	i = 0;
	while(i < info->num_of_philo)
	{
		if(pthread_join((philos + i)->tid, NULL))
			return (-1);
		printf("%d\n", i);
	}
	if(pthread_mutex_destroy(philos->mutex))
		return (-1);

	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	int		*forks;
	t_info	*info;

	if(!check_argv(argc, argv))
		return(return_error(1, "arguments error!"));
	info = set_info(argc, argv);
	forks = set_forks(info);
	philos = init_philos(info, forks);	
	end_philo(info,  philos);
}

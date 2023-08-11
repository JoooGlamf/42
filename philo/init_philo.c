/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:34 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 12:46:25 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_info	*init_info(char **argv)
{
	t_info	*output;
	int		i;

	output = (t_info *)malloc(sizeof(t_info));
	output->num_of_philo = ft_itoa(argv[1]);
	output->time_to_die = ft_itoa(argv[2]);
	output->time_to_eat = ft_itoa(argv[3]);
	output->time_to_sleep = ft_itoa(argv[4]);
	return (output);
}

p_thread_t	*init_philos(t_info *info)
{
	t_philo	philos;
	int		i;

	output = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo); 
	i = 0;
	while(i < info->num_of_philo)
	{
		pthread_create((output + i)->tid, NULL, actions, info);
		output->left_fork = i;
		output->right_fork = (i + 1) % info->num_of_philo;
		output->numbers_eat = 0;
		++i;
	}
	return (output);
}

int	*init_forks(t_info *info)
{
	int	*output;
	int	i;

	output = (int *)malloc(sizeof(int) * info->num_of_philo);
	i = 0;
	while(i < info->num_of_philo)
	{
		output[i] = 1;
		++i;
	}
	return (output);
}

t_data	*init_data(int argc, char **argv)
{
	data->info = init_info(argv);
	data->philos = init_philos(data->info);
	data->forks = init_forks(data->info);
}

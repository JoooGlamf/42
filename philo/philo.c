/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 18:24:48 by soojoo           ###   ########.fr       */
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

	if(argc != 5 && argc != 6)/
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

int	end_philo(t_data *data)
{
	int	i;
	i = 0;
	while(i < data->info->num_of_philo)
	{
		if(pthread_join(((data->philos) + i)->tid, NULL))
			return (-1);
		++i;
	}
	if(pthread_mutex_destroy(data->philos->mutex))
		return (-1);
	//동적할당 한 것들 해제하는 것 추가 할 것
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if(!check_argv(argc, argv))
		return(return_error(1, "arguments error!"));		
	data = init_data(argc, argv);
	end_philo(data);
}

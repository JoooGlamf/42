/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:12:43 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/06 20:34:19 by soojoo           ###   ########.fr       */
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

	if(argc != 6)//number_of_times_each_philosopher_must_eat
	{
		printf("arguments error!\n");
		return (1);
	}
	i  = 0;
	while(i < argc)
	{
		j = 0;
		while(j < argv[i][0])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}


int	main(int argc, char **argv)
{
	if(!check_argv(argc, argv))
		return(return_error(1, "arguments error!");
	
}

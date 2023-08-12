/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:11:44 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/11 17:29:21 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>

typedef struct	s_info
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_must_eat;
	long long	init_time;
}	t_info;

typedef struct	s_philo
{
	pthread_t	tid;
	int			*left_fork;
	int			*right_fork;
	int			numbers_eat;
	pthread_mutex_t	*mutex;
}	t_philo;

typedef struct	s_data
{
	t_info	*info;
	t_philo	*philos;
	int		*forks;
}	t_data;

//init_philo.c
t_info		*init_info(int argc, char **argv);
int			*init_forks(t_info *info);
t_philo		*init_philos(t_data *data);
t_data		*init_data(int argc, char **argv);

//philo_utils.c
long long	get_current_time();
long long	get_running_time(int start_time);
int			ft_atoi(const char *str);

//philo_actions.c
void	*actions(void *philo);
#endif

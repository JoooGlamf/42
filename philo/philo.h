/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:11:44 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/14 04:36:57 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>

typedef struct	s_argv	
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_must_eat;
}	t_argv;

typedef struct	s_data
{
	t_argv			*argv;
	pthread_mutex_t	*mutexes;
	int				*forks;
	int				philo_num;
	//int				*left_fork;
	//int				*right_fork;
	int				numbers_eat;
	long long		init_time;
	long long		last_eat_time;
}	t_data;

//init_philo.c
t_argv			*init_argv(int argc, char **argv);
int				*init_forks(t_argv *argv);
pthread_mutex_t	*init_mutexes(t_argv *argv);
t_data			*init_datas(int argc, char **argv);
pthread_t		*init_philos(t_data *data);

//philo_utils.c
long long	convert_time_ms(struct timeval time);
long long	get_current_time_ms();
long long	get_running_time_ms(long long init_time_ms);
int			ft_atoi(const char *str);

//philo_actions.c
void	*actions(void *void_philo);
//int		think_philo(t_philo *philo);
//int		eat_philo(t_philo *philo);
//int		sleep_philo(t_philo *philo);
#endif

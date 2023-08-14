/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:11:44 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/14 23:34:24 by soojoo           ###   ########.fr       */
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

typedef struct	s_mutexes
{
	pthread_mutex_t *forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*time_mutex;
}	t_mutexes;

typedef struct	s_data
{
	t_argv		*argv;
	t_mutexes	*mutexes;
	int			philo_num;
	int			numbers_eat;
	long long	init_time;
	long long	running_time;
	long long	last_eat_time;
}	t_data;

//init_philo.c
t_argv		*init_argv(int argc, char **argv);
int			*init_forks(t_argv *argv);
t_mutexes	*init_mutexes(t_argv *argv);
t_data		*init_data(int argc, char **argv);
pthread_t	*init_philos(t_data *data);

//philo_utils.c
long long	convert_time_ms(struct timeval time);
long long	get_current_time_ms();
long long	get_running_time_ms(pthread_mutex_t *time_mutex, long long init_time_ms);
int			exact_sleep(long long sleep_time);
int			ft_atoi(const char *str);
int			locked_printf(pthread_mutex_t *mutex, long long time, int philo_num, char *status);

//philo_actions.c
void	*actions(void *void_data);
void	think_action(t_data *data);
void	eat_action_odd(t_data *data);
void	eat_action_even(t_data *data);
void	sleep_action(t_data *data);
#endif

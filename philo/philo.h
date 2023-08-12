/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:11:44 by soojoo            #+#    #+#             */
/*   Updated: 2023/08/12 21:00:44 by soojoo           ###   ########.fr       */
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
	pthread_t		tid;
	pthread_mutex_t	*mutex;
	t_info			*info;
	int				*left_fork;
	int				*right_fork;
	int				numbers_eat;
	long long		last_eat_time;
}	t_philo;

//init_philo.c
t_info		*set_info(int argc, char **argv);
int			*set_forks(t_info *info);
t_philo		*init_philos(t_info *info, int *forks);

//philo_utils.c
long long	convert_time_ms(struct timeval time);
long long	get_current_time_ms();
long long	get_running_time_ms(long long init_time_ms);
int			ft_atoi(const char *str);

//philo_actions.c
void	*actions(void *void_philo);
#endif

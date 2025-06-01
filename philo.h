/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:28:53 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/25 19:28:53 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647

typedef struct s_args
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	loop_time;
}				t_args;

typedef struct s_philo
{
	int				id;
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	long long		last_meal;
	int				meal_times;
}				t_philo;

typedef struct s_table
{
	t_args			*args;
	t_philo			*philos;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}				t_table;

int			arg_check(char **argv);
void		get_args(t_args *args, char **argv);
long long	get_timestamp(void);
t_table		*init_table(t_args *args);
void		free_table(t_table *table);
int			init_forks(t_table *table);
void		init_philos(t_table *table);
t_table		*get_my_table(t_args *args);
void		main_program(t_table *table);

#endif

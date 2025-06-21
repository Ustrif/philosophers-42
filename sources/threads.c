/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:05:16 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/21 15:56:48 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_cycle(t_philo *philo, long long time)
{
	print_status(philo, "is eating", time, philo->id);
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->state_mutex);
	usleep(philo->args->time_to_eat * 1000);
	philo->meal_times++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_status(philo, "is sleeping", time, philo->id);
	usleep(philo->args->time_to_sleep * 1000);
	print_status(philo, "is thinking", time, philo->id);
}

void	*routine(void *p)
{
	long long	time;
	t_philo		*philo;

	time = get_timestamp();
	philo = (t_philo *) p;
	while (philo->meal_times < philo->args->loop_time
		|| philo->args->loop_time == -1)
	{
		pthread_mutex_lock(&philo->table->state_mutex);
		if (philo->table->dead == 1)
		{
			pthread_mutex_unlock(&philo->table->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->state_mutex);
		take_forks(philo, time);
		philo_cycle(philo, time);
	}
	pthread_mutex_lock(&philo->state_mutex);
	philo->full = 1;
	pthread_mutex_unlock(&philo->state_mutex);
	return (NULL);
}

void	joiner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_num)
	{
		pthread_join(table->philos[i].thread, NULL);
		usleep(100);
		i = i + 2;
	}
	i = 1;
	while (i < table->args->philo_num)
	{
		pthread_join(table->philos[i].thread, NULL);
		usleep(100);
		i = i + 2;
	}
}

void	main_two(t_table *table)
{
	pthread_t	mt;
	int			i;

	i = 0;
	while (i < table->args->philo_num)
	{
		pthread_create(&table->philos[i].thread, NULL, routine,
			&table->philos[i]);
		usleep(100);
		i = i + 2;
	}
	i = 1;
	while (i < table->args->philo_num)
	{
		pthread_create(&table->philos[i].thread, NULL, routine,
			&table->philos[i]);
		usleep(100);
		i = i + 2;
	}
	pthread_create(&mt, NULL, monitor, table);
	joiner(table);
	pthread_join(mt, NULL);
}

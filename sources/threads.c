/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:05:16 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/01 10:37:58 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo	*p, char *t, int time, int id)
{
	pthread_mutex_lock(p->print);
	printf("%d %d %s\n", time, id, t);
	pthread_mutex_unlock(p->print);
}

void	*routine(void *p)
{
	int		time;
	t_philo	*philo;

	time = get_timestamp();
	philo = (t_philo *) p;
	while (1)
	{
		if (get_timestamp() - philo->last_meal > philo->args->time_to_die)
		{
			pthread_mutex_lock(&philo->state_mutex);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->state_mutex);
			break ;
		}
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a fork", get_timestamp() - time, philo->id);
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken a fork", get_timestamp() - time, philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken a fork", get_timestamp() - time, philo->id);
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a fork", get_timestamp() - time, philo->id);
		}
		print_status(philo, "is eating", get_timestamp() - time, philo->id);
		usleep(philo->args->time_to_eat * 1000);
		philo->meal_times++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->last_meal = get_timestamp();
		if (philo->meal_times == philo->args->loop_time)
			break ;
		print_status(philo, "is sleeping", get_timestamp() - time, philo->id);
		usleep(philo->args->time_to_sleep * 1000);
		print_status(philo, "is thinking", get_timestamp() - time, philo->id);
	}
	return (NULL);
}

void	*monitor(void *table)
{
	t_table		*t;
	int			i;
	long long	time;

	t = (t_table *) table;
	i = 0;
	time = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&t->philos[i].state_mutex);
		if (t->philos[i].dead == 1)
			break ;
		pthread_mutex_unlock(&t->philos[i].state_mutex);
		usleep(500);
		i++;
		if (i == t->args->philo_num)
			i = 0;
	}
	pthread_mutex_unlock(&t->philos[i].state_mutex);
	printf("%lld %d died\n", get_timestamp() - time, i);
	return (NULL);
}

void	main_two(t_table	*table)
{
	pthread_t	mt;

	pthread_create(&table->philos[0].thread, NULL, routine, &table->philos[0]);
	pthread_create(&table->philos[1].thread, NULL, routine, &table->philos[1]);
	pthread_create(&mt, NULL, monitor, table);
	pthread_join(table->philos[0].thread, NULL);
	pthread_join(table->philos[1].thread, NULL);
	pthread_join(mt, NULL);
}

void	main_program(t_table *table)
{
	int	num;

	num = table->args->philo_num;
	if (num == 2)
		main_two(table);
	/*if (num == 3)
	else if (num % 2 == 0 && num > 4)*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:05:16 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/01 13:57:05 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo	*p, char *t, int time, int id)
{
	pthread_mutex_lock(p->print);
	pthread_mutex_lock(&p->table->state_mutex);
	if (p->table->dead != 1)
		printf("%d %d %s\n", time, id, t);
	pthread_mutex_unlock(&p->table->state_mutex);
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
		pthread_mutex_lock(&philo->table->state_mutex);
		if (philo->table->dead == 1)
		{
			pthread_mutex_unlock(&philo->table->state_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->state_mutex);
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
		philo->last_meal = get_timestamp();
		usleep(philo->args->time_to_eat * 1000);
		philo->meal_times++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (philo->meal_times == philo->args->loop_time)
			break ;
		print_status(philo, "is sleeping", get_timestamp() - time, philo->id);
		usleep(philo->args->time_to_sleep * 1000);
		print_status(philo, "is thinking", get_timestamp() - time, philo->id);
	}
	pthread_mutex_lock(&philo->state_mutex);
	philo->full = 1;
	pthread_mutex_unlock(&philo->state_mutex);
	return (NULL);
}

void	*monitor(void *table)
{
	t_table		*t;
	int			i;
	long long	time;
	int			y;
	int			flag;

	t = (t_table *) table;
	i = 0;
	flag = 1;
	time = get_timestamp();
	while (flag)
	{
		pthread_mutex_lock(&t->philos[i].state_mutex);
		if ((get_timestamp() - t->philos[i].last_meal) > t->args->time_to_die)
			break ;
		pthread_mutex_unlock(&t->philos[i].state_mutex);
		usleep(500);
		y = 0;
		while (y < t->args->philo_num)
		{
			pthread_mutex_lock(&t->philos[i].state_mutex);
			if (t->philos[i].full != 1)
			{
				pthread_mutex_unlock(&t->philos[i].state_mutex);
				break ;
			}
			pthread_mutex_unlock(&t->philos[i].state_mutex);
			y++;
			if ((y < t->args->philo_num) == 0)
				flag = 0;
		}
		i++;
		if (i == t->args->philo_num)
			i = 0;
	}
	pthread_mutex_unlock(&t->philos[i].state_mutex);
	pthread_mutex_lock(&t->state_mutex);
	t->dead = 1;
	pthread_mutex_unlock(&t->state_mutex);
	if (flag)
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

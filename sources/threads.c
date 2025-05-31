/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:05:16 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/31 13:11:50 by raydogmu         ###   ########.fr       */
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
		usleep(philo->args->time_to_eat);
		philo->meal_times++;
		philo->last_meal = get_timestamp();
		print_status(philo, "is sleeping", get_timestamp() - time, philo->id);
		usleep(philo->args->time_to_sleep);
		print_status(philo, "is thinking", get_timestamp() - time, philo->id);
	}
	return (NULL);
}

/*void *monitor(void *ar)
{
	t_table *t = (t_table *) ar;
	int 	i;
	int 	full;

	if (t->args->loop_time < 0)
		return (NULL);
	while (1)
	{
		full = 0;
		i = 0;
		while (i < t->args->philo_num)
		{
			if (t->philos[i].meal_times >= t->args->loop_time)
				full++;
			i++;
		}
		if (full == t->args->philo_num)
			break;
		usleep(1000);
	}
	return (NULL);
}*/

void	main_program(t_table *table)
{
	int			i;
	//pthread_t	mon;
	
	i = 0;
	//pthread_create(&mon, NULL, monitor, table);
	while (i < table->args->philo_num)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->args->philo_num)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	//pthread_join(mon, NULL);
}

// @Ustrif ➜ /workspaces/philosophers-42 (main) $ ./philo 2 1000000 2000000 3000000 4
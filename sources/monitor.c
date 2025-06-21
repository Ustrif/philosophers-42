/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:46:18 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/21 14:55:35 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	dead_print(t_table *t, int flag, long long time, int i)
{
	pthread_mutex_lock(&t->state_mutex);
	if (flag)
		t->dead = 1;
	pthread_mutex_unlock(&t->state_mutex);
	if (flag)
		printf("%lld %d died\n", get_timestamp() - time, i + 1);
}

int	next_index(int current, int max)
{
	current++;
	if (current == max)
		return (0);
	return (current);
}

int	control(t_table *t, int i)
{
	pthread_mutex_lock(&t->philos[i].state_mutex);
	if (t->philos[i].full != 1 && ((get_timestamp() - t->philos[i].last_meal)
			> t->args->time_to_die))
	{
		pthread_mutex_unlock(&t->philos[i].state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&t->philos[i].state_mutex);
	return (0);
}

void	*monitor1(t_table *t, int flag, int i, int y)
{
	while (flag)
	{
		if (control(t, i))
			break ;
		y = 0;
		while (y < t->args->philo_num)
		{
			pthread_mutex_lock(&t->philos[y].state_mutex);
			if (t->philos[y].full != 1)
			{
				pthread_mutex_unlock(&t->philos[y].state_mutex);
				break ;
			}
			pthread_mutex_unlock(&t->philos[y].state_mutex);
			if (++y == t->args->philo_num)
				return (NULL);
		}
		i = next_index(i, t->args->philo_num);
	}
	dead_print(t, flag, t->start_time, i);
	return (NULL);
}

void	*monitor(void *table)
{
	t_table	*t;

	t = (t_table *) table;
	return (monitor1(t, 1, 0, 0));
}

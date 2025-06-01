/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:05:37 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/01 12:18:16 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*init_table(t_args *args)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->args = args;
	table->philos = malloc(sizeof(t_philo) * args->philo_num);
	if (!table->philos)
		return (free(table), NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * args->philo_num);
	if (!table->forks)
	{
		free(table->philos);
		free(table);
		return (NULL);
	}
	table->start_time = get_timestamp();
	table->dead = 0;
	table->full_count = 0;
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->state_mutex, NULL);
	return (table);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_num)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_init(&table->state_mutex, NULL);
	free(table->forks);
	free(table->philos);
	free(table->args);
	free(table);
}

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_num)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->philos[i].state_mutex, NULL);
		i++;
	}
	return (0);
}

void	init_philo(t_philo *philo, int id, t_table *table)
{
	philo->id = id;
	philo->args = table->args;
	philo->table = table;
	philo->thread = 0;
	philo->left_fork = &table->forks[id];
	philo->right_fork = &table->forks[(id + 1) % table->args->philo_num];
	philo->print = &table->print_mutex;
	philo->last_meal = get_timestamp();
	philo->meal_times = 0;
	pthread_mutex_init(&philo->state_mutex, NULL);
	philo->dead = 0;
	philo->full = 0;
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->philo_num)
	{
		init_philo(&table->philos[i], i, table);
		i++;
	}
}

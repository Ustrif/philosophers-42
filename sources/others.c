/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:24:39 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/02 15:29:07 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo, long long time)
{
	if (philo->id % 2 == 0)
	{
		if (philo->args->philo_num % 2 == 0)
			usleep(500);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", time, philo->id);
	}
	else
	{
		if (philo->args->philo_num % 2 == 0)
			usleep(500);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", time, philo->id);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", time, philo->id);
	}
}

void	take_forks1(t_philo *philo, long long time)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork", time, philo->id);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork", time, philo->id);
}

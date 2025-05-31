/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:30:49 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/25 19:30:49 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

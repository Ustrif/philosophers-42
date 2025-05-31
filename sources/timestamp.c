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

int	get_timestamp(void)
{
	struct timeval	ts;
	int				timestamp;

	gettimeofday(&ts, NULL);
	timestamp = ts.tv_usec / 1000 + ts.tv_sec * 1000;
	return (timestamp);
}

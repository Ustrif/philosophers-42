/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:07:32 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/01 19:19:24 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_status(t_philo	*p, char *t, long long time, int id)
{
	pthread_mutex_lock(p->print);
	pthread_mutex_lock(&p->table->state_mutex);
	if (p->table->dead != 1)
		printf("%lld %d %s\n", get_timestamp() - time, id + 1, t);
	pthread_mutex_unlock(&p->table->state_mutex);
	pthread_mutex_unlock(p->print);
}

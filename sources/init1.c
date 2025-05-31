/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:09:55 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/29 13:12:23 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*get_my_table(t_args *args)
{
	t_table	*table;
	int		result;

	table = init_table(args);
	if (!table)
		return (NULL);
	result = init_forks(table);
	if (result < 0)
		return (NULL);
	init_philos(table);
	return (table);
}

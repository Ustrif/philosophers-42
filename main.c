/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:29:55 by raydogmu          #+#    #+#             */
/*   Updated: 2025/06/01 20:22:53 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_program(t_table *table)
{
	int			num;
	long long	time;

	num = table->args->philo_num;
	if (num >= 2 && num % 2 == 0)
		main_two(table);
	else if (num >= 2 && num % 2 != 0)
		main_odd(table);
	else if (num == 1)
	{
		time = get_timestamp() - table->start_time;
		printf("%lld 1 has taken a fork\n", time);
		usleep(table->args->time_to_die * 1000);
		printf("%lld %d is dead\n", get_timestamp() - table->start_time, 1);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;
	t_table	*table;

	if (!(argc >= 5 && argc <= 6) || arg_check(argv))
		return (printf("Invalid arguments.\n"), 1);
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	get_args(args, argv);
	table = get_my_table(args);
	if (!table)
	{
		printf("NO TABLE!\n");
		free(args);
	}
	main_program(table);
	free_table(table);
	return (0);
}
// -g kaldir.
// 
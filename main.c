/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:29:55 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/31 17:22:07 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		printf("NO TABLE!");
		free(args);
	}
	main_program(table);
	free_table(table);
	//printf("calisti. :)\n");
	//printf("%d \n", get_timestamp());
	return (0);
}

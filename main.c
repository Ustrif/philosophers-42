/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:29:55 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/25 19:30:32 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (!(argc >= 5 && argc <= 6) || arg_check(argv))
		return (1);
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	get_args(args, argv);
	free(args);
	printf("calisti. :)\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:28:53 by raydogmu          #+#    #+#             */
/*   Updated: 2025/05/25 19:28:53 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h> // memset

# define INT_MAX 2147483647

typedef struct s_args
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	loop_time;
}				t_args;

int		arg_check(char **argv);
void	get_args(t_args *args, char **argv);
int		get_timestamp(void);

#endif

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h> // memset

typedef struct s_args {
	int	philo_num;
	int time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int loop_time;
} t_args;

int		arg_check(char **argv);
void	get_args(t_args *args, char **argv);
int		get_timestamp();

#endif

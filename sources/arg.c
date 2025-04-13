#include "../philo.h"

int ft_char_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;

	result = 0;
	if (!str)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
			return (-1);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int) result);
}

int	arg_check(char **argv)
{
	int i;
	int result;

	result = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_char_check(argv[i]) || (ft_atoi(argv[i]) == -1))
			result = 1;
		i++;
	}
	return (result);
}

void	get_args(t_args *args, char **argv)
{
	args->philo_num = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->loop_time = ft_atoi(argv[5]);
}

#include "../philo.h"

int	get_timestamp()
{
	struct timeval	ts;
	int 			timestamp;

	gettimeofday(&ts, NULL);
	timestamp = ts.tv_usec / 1000;
	return (timestamp);
}

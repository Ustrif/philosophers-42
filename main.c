#include "philo.h"

int main(int argc, char **argv)
{
	t_args	*args;

	if (!(argc >= 5 && argc <= 6) || arg_check(argv))
		return (1);
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	get_args(args, argv);
	// devam.
	free(args);
	printf("calisti. :)");
	return 0;
}

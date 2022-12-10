# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
#include <pthread.h>

typedef struct philo_info{
	size_t	number_of_philo;
	int		time_to_eat;
	int		time_to_sleep;
    int     left_fork;
    int     right_fork;
}philo_t;
#include "test_philo.h"

void take_leftfork()
{

}

void take_right_fork()
{

}

void eat_func()
{

}

void sleep_func()
{

}

void think_funk()
{
    
}

void *philo_life()
{

}

void readey_forphilolife(int philonum, int eat_time, int think_time, int die_time)
{
    pthread_t   *handler;
    int         i;

    handler = (pthread_t *)malloc(sizeof(pthread_t) * philonum);
    i = 0;
    while (i != philonum)
        pthread_create(&handler[i], NULL, &philo_life, NULL);
    i = 0;
    while (i != philonum)
        pthread_join(handler[i], NULL);
    return (0)
}

int main()
{
    int PHILO_NUM = 2;
    int PHILO_EAT = 10;
    int PHILO_THINK = 10;
    int PHILO_TODEATH = 30;

    readey_forphilolife(PHILO_NUM, PHILO_EAT, PHILO_THINK, PHILO_TODEATH);
}
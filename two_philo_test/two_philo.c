#include "test_philo.h"

void take_fork(int r_f, int l_f, int number)
{
    printf("%d's fork is take up by %d\n", r_f, number);
    printf("%d's fork is take up by %d\n", l_f, number);
}

void put_fork(int l_f, int r_f, int number)
{
    printf("%d's fork is puted by %d\n", r_f, number);
    printf("%d's fork is puted by %d\n", l_f, number);
}

void eat_func(int think_time, int number)
{
    usleep(think_time);
    printf("%d thinked, end\n",  number);
}

void sleep_func(int sleep_time)
{
    usleep(sleep_time);
}

void think_funk(int thinktime, int r_fork, int l_fork, int number)
{
    take_fork(r_fork, l_fork, number);
    eat_func(thinktime, number);
}

void* philo_life(void *any_philoinfo)
{
    philo_t *philoinfo;

    philoinfo = (philo_t *)any_philoinfo;
    int i = 0;
    while (i != 10)
    {
        think_funk(philoinfo->time_to_eat, philoinfo->right_fork, philoinfo->left_fork, philoinfo->number_of_philo);
        put_fork(philoinfo->right_fork, philoinfo->left_fork, philoinfo->number_of_philo);
        sleep_func(philoinfo->time_to_sleep);
        i++;
    }
    return (NULL);
}

void readey_forphilolife(int philonum, int eat_time, int sleep_time, int die_time)
{
    pthread_t       *handler;
    philo_t         *philoinfo;
    //pthread_mutex_t fork;
    //pthread_mutex_t *forks;
    int             *forks;
    int             i;

    handler = (pthread_t *)malloc(sizeof(pthread_t) * philonum);
    philoinfo = (philo_t *)malloc(sizeof(philo_t) * philonum);
    forks = (int *)malloc(sizeof(int) * philonum);
    i = 0;
    while (i != philonum)
    {
        forks[i] = i;
        i++;
    }
    // i = 0;
    // while (i != philonum)
    // {
    //     forks = pthread_mutex_init(&fork, NULL);
    //     i++;
    // }
    i = 0;
    while (i != philonum)
    {
        philoinfo[i].number_of_philo = (size_t)i;
        philoinfo[i].time_to_sleep = sleep_time;
        philoinfo[i].time_to_eat = eat_time;
        if (i == 0)
        {
            philoinfo[i].right_fork = forks[philonum - 1];
            philoinfo[i].left_fork = forks[0];
        }
        else
        {
            philoinfo[i].right_fork = forks[i - 1];
            philoinfo[i].left_fork = forks[i];
        }
        pthread_create(&handler[i], NULL, &philo_life, &philoinfo[i]);
        i++;
    }
    i = 0;
    while (i != philonum)
    {
        pthread_join(handler[i], NULL);
        i++;
    }
}

int main()
{
    int PHILO_NUM = 2;
    int PHILO_EAT = 10;
    int PHILO_TODEATH = 30;
    int PHILO_SLEEP = 10;

    readey_forphilolife(PHILO_NUM, PHILO_TODEATH, PHILO_EAT, PHILO_SLEEP);
}
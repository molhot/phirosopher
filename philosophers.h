/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:45 by satushi           #+#    #+#             */
/*   Updated: 2022/12/10 07:11:01 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERES_H
# define PHILOSOPHERES_H

// #ifndef number_of_philosophers
// # define number_of_philosophers 3
// #endif

// #ifndef time_to_die
// # define time_to_die 100
// #endif

// #ifndef time_to_eat
// # define time_to_eat 20
// #endif

// #ifndef time_to_sleep
// # define time_to_sleep 20
// #endif

# define ERROR_ARGUMENTNUM 1
# define ERROR_MALLOC 2

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
    int		time_to_die;
	int		time_to_eat;
	int		time_tosleep;
}philo_t;

typedef struct all_info{
	pthread_mutex_t fork_l_mutex;
	pthread_mutex_t fork_r_mutex;
	pthread_mutex_t eat_mutex;
	philo_t			philoinfo;
}philo_allinfo_t;

int		print_errormessage(int errornum);
int		ft_atoi(const char *str);
size_t	grasp_charlen(char *sentence);
void	ft_putchar_fd(char *error_sentence);
void	*philo_func();
void	eat(int eat_time);
void	think(int think_time);
void	sleeping(int sleeping_time);

#endif
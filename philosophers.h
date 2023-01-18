/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:45 by satushi           #+#    #+#             */
/*   Updated: 2023/01/18 21:40:17 by satushi          ###   ########.fr       */
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

# define ERROR_ARGUMENT 1
# define ERROR_MALLOC 2
# define ERROR_PHILOINFO 3

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct s_fork{
	int	l_fork;
	int	r_fork;
}t_fork;

typedef struct philo_info{
	size_t			number_of_philo;
	size_t			how_eated;
	pthread_t		philo_thread;
	t_fork			fork_info;
	long	long	time_to_die;
}t_philo;

typedef struct all_info{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	long long		start_time;
	t_philo			*philoinfo;
	pthread_t		checkthread;
	int				philo_num;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				eat_limit;
	int				time_to_die;
	int				thread_num;
	bool			philo_die_ornot;
}t_allinfo;

int				print_errormessage(int errornum);
int				ft_atoi(const char *str);
size_t			grasp_charlen(char *sentence);
void			ft_putchar_fd(char *error_sentence);
bool			think(t_allinfo *info, int pn);
bool			sleeping(t_allinfo *info, int pn);
bool			arg_check(int argnum, char **arg);
void			*philo_func(void *info);
bool			print_action(t_allinfo *info, int ph_num, char *action);
void			*philo_checker();
long	long	get_time();
long	long	passing_time(long long time);
bool			eat_drop_add(t_allinfo *info, int l_f, int r_f, int i);
bool			eat_drop_even(t_allinfo *info, int l_f, int r_f, int i);

#endif
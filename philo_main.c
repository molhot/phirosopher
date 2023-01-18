/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2023/01/18 20:46:35 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	ready_philoinfo(t_allinfo *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->philo_die_ornot = false;
	if (argc == 6)
		info->eat_limit = ft_atoi(argv[5]);
	else
		info->eat_limit = -1;
	info->start_time = get_time();
}

static	bool	create_samephilo(t_allinfo *info)
{
	int	l_f_n;

	l_f_n = 2;
	info->philoinfo = (t_philo *)malloc(sizeof(t_allinfo) * info->philo_num);
	if (info->philoinfo== NULL)
		return (false);
	while (l_f_n != info->philo_num + 1)
	{
		((info->philoinfo)[l_f_n - 1]).fork_info.r_fork = l_f_n - 2;
		((info->philoinfo)[l_f_n - 1]).fork_info.l_fork = l_f_n - 1;
		((info->philoinfo)[l_f_n - 1]).how_eated = 0;
		((info->philoinfo)[l_f_n - 1]).number_of_philo = l_f_n;
		((info->philoinfo)[l_f_n - 1]).time_to_die = 0;
		l_f_n++;
	}
	((info->philoinfo)[0]).fork_info.r_fork = info->philo_num - 1;
	((info->philoinfo)[0]).fork_info.l_fork = 0;
	((info->philoinfo)[0]).how_eated = 0;
	((info->philoinfo)[0]).number_of_philo = 1;
	((info->philoinfo)[0]).time_to_die = 0;
	return (true);
}

static	bool	create_forks(t_allinfo *info)
{
	int	fork_num;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->forks == NULL)
		return (false);
	fork_num = 0;
	while (fork_num != info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[fork_num], NULL) != 0)
			return (false);
		fork_num++;
	}
	return (true);
}

static	bool	create_threads(t_allinfo *info)
{
	size_t philo_num;

	philo_num = 0;
	while ((int)philo_num != info->philo_num)
	{
		info->thread_num = philo_num;
		if (pthread_create(&info->philoinfo[philo_num].philo_thread, NULL, &philo_func, (void *)info) != 0)
			return (false);
		philo_num++;
		usleep(1000);
	}
	if (pthread_create(&info->checkthread, NULL, &philo_checker, (void *)info) != 0)
			return (false);
	usleep(1000);
	philo_num = 0;
	while ((int)philo_num != info->philo_num)
	{
		if (pthread_join(((info->philoinfo)[philo_num]).philo_thread, NULL) != 0)
			return (false);
		philo_num++;
	}
	if (pthread_join(info->checkthread, NULL) != 0)
			return (false);
	return (true);
}

int main(int argc, char *argv[])
{
	t_allinfo	allinfo;

	if (arg_check(argc, argv) == false)
		return (1);
	ready_philoinfo(&allinfo, argc, argv);
	if (create_samephilo(&allinfo) == false)
		return (1);
	if (create_forks(&allinfo) == false)
		return (1);
	allinfo.philo_die_ornot = false;
	if (pthread_mutex_init(&(allinfo.write), NULL) != 0)
		return (1);
	if (create_threads(&allinfo) == false)
		return (1);
	printf("thread is correctly ended\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:02 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:07:02 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	ready_philoinfo(t_allinfo *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->time_to_think = 0;
	info->philo_die_ornot = false;
	if (argc == 6)
		info->eat_limit = ft_atoi(argv[5]);
	else
		info->eat_limit = -1;
}

int main(int argc, char *argv[])
{
	t_allinfo	allinfo;
	// int			num;

	if (arg_check(argc, argv) == false)
		return (1);
	ready_philoinfo(&allinfo, argc, argv);
	if (mutexinit(&allinfo) == false)
		return (1);
	pthread_mutex_init(&(allinfo.timecheck), NULL);
	if (create_forks(&allinfo) == false)
		return (1);
	if (create_samephilo(&allinfo) == false)
		return (1);
	allinfo.philo_die_ornot = false;
	if (allinfo.eat_limit != -1)
	{
		if (create_threads(&allinfo) == false)
			return (1);
	}
	else
	{
		if (create_threads_ult(&allinfo) == false)
			return (1);
	}
	// num = 0;
	// while (num != allinfo.philo_num)
	// {
	// 	pthread_mutex_destroy(&allinfo.status[num]);
	// 	strerror(pthread_mutex_destroy(&allinfo.forks[num]));
	// 	num++;
	// }
}

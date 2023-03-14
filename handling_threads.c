/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2023/03/14 19:42:39 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	create_threads(t_allinfo *info)
{
	size_t	philo_num;
	t_philo	*subject;

	philo_num = 0;
	while (1)
	{
		pthread_mutex_lock(&info->thread);
		info->thread_num = philo_num;
		info->philoinfo[philo_num].philo_livedstart = getnowtime();
		subject = &((info->philoinfo)[philo_num]);
		if (pthread_create(&info->philoinfo[philo_num].philo_thread, NULL, &limited_philolife_add, (void *)subject) != 0)
			return (false);
		pthread_detach(info->philoinfo[philo_num].philo_thread);
		philo_num = philo_num + 2;
		if ((int)philo_num > info->philo_num)
		{
			pthread_mutex_unlock(&info->thread);
			break ;
		}
		pthread_mutex_unlock(&info->thread);
	}
	usleep(200);
	philo_num = 1;
	while (1)
	{
		pthread_mutex_lock(&info->thread);
		info->thread_num = philo_num;
		info->philoinfo[philo_num].philo_livedstart = getnowtime();
		subject = &((info->philoinfo)[philo_num]);
		if (pthread_create(&info->philoinfo[philo_num].philo_thread, NULL, &limited_philolife_even, (void *)subject) != 0)
			return (false);
		pthread_detach(info->philoinfo[philo_num].philo_thread);
		philo_num = philo_num + 2;
		if ((int)philo_num > info->philo_num)
		{
			pthread_mutex_unlock(&info->thread);
			break ;
		}
		pthread_mutex_unlock(&info->thread);
	}
	usleep(200);
	if (pthread_create(&info->checkthread, NULL, &philo_checker, (void *)info) != 0)
			return (false);
	usleep(100);
	if (pthread_join(info->checkthread, NULL) != 0)
			return (false);
	return (true);
}

int	destroy_threads(t_allinfo *main)
{
	int	i;

	i = 0;
	while (i < main->philo_num)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	return (0);
}
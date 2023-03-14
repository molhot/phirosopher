/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2023/03/14 20:25:34 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	start_philolife(t_philo *subject)
{
	if (pthread_create(&(subject->philo_thread), NULL, &philolife_life, (void *)(subject)) != 0)
		return (false);
	pthread_detach(subject->philo_thread);
	return (true);
}

bool	create_threads(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	while ((int)philo_num < info->philo_num)
	{
		start_philolife(&((info->philoinfo)[philo_num]));
		philo_num = philo_num + 2;
	}
	usleep(200);
	philo_num = 1;
	while ((int)philo_num < info->philo_num)
	{
		start_philolife(&((info->philoinfo)[philo_num]));
		philo_num = philo_num + 2;
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

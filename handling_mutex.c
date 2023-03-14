/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:27:12 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:27:12 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	mutexinit(t_allinfo *allinfo)
{
	if (pthread_mutex_init(&(allinfo->write), NULL) != 0)
		return (false);
	return (true);
}

bool	create_forks(t_allinfo *info)
{
	int	fork_num;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->status = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->forks == NULL)
		return (false);
	if (info->status == NULL)
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
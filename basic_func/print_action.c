/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:51 by satushi           #+#    #+#             */
/*   Updated: 2023/01/12 12:29:55 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	print_action(t_allinfo *info, int ph_num, char *action)
{
	pthread_mutex_lock(&info->write);
	if (info->philo_die_ornot == true)
	{
		printf("philo is dead");
		pthread_mutex_unlock(&info->write);
		return (false);
	}
	printf("%d's philo is take {%s}\n", ph_num, action);
	pthread_mutex_unlock(&info->write);
	return (true);
}
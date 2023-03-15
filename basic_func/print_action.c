/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:51 by satushi           #+#    #+#             */
/*   Updated: 2023/03/15 13:29:22 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	print_action(t_philo *info, char *action)
{
	long long	time;

	if (info->all_info->philo_die_ornot == true)
		return (false);
	pthread_mutex_lock(&info->all_info->write);
	time = getnowtime();
	if (info->all_info->philo_die_ornot == true)
	{
		pthread_mutex_unlock(&info->all_info->write);
		return (false);
	}
	printf("%lld %ld %s\n", time, info->number_of_philo, action);
	pthread_mutex_unlock(&info->all_info->write);
	return (true);
}
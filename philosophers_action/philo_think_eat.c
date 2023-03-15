/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/15 19:26:29 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

bool	eat_drop(t_philo *info, int l_f, int r_f)
{
	if (pthread_mutex_lock(&info->all_info->forks[l_f]) != 0)
		return (false);
	if (print_action(info, "has taken a fork") == false)
	{
		pthread_mutex_unlock(&info->all_info->forks[l_f]);
		return (false);
	}
	if (pthread_mutex_lock(&info->all_info->forks[r_f]) != 0)
		return (false);
	if (print_action(info, "has taken a fork") == false)
	{
		pthread_mutex_unlock(&info->all_info->forks[r_f]);
		pthread_mutex_unlock(&info->all_info->forks[l_f]);
		return (false);
	}
	if (print_action(info, "is eating") == false)
	{
		pthread_mutex_unlock(&info->all_info->forks[r_f]);
		pthread_mutex_unlock(&info->all_info->forks[l_f]);
		return (false);
	}
	usleep(1000 * (long long)info->all_info->time_to_eat);
	pthread_mutex_unlock(&info->all_info->forks[r_f]);
	pthread_mutex_unlock(&info->all_info->forks[l_f]);
	if (l_f - r_f != 1)
	{
		pthread_mutex_lock(&(info->all_info->status[r_f]));
		info->how_eated = info->how_eated + 1;
		info->philo_livedstart = getnowtime();
		pthread_mutex_unlock(&(info->all_info->status[r_f]));
	}
	else
	{
		pthread_mutex_lock(&(info->all_info->status[l_f]));
		info->how_eated = info->how_eated + 1;
		info->philo_livedstart = getnowtime();
		pthread_mutex_unlock(&(info->all_info->status[l_f]));
	}
	return (true);
}

bool	think(t_philo *info)
{
	if (info->all_info->philo_die_ornot == true)
		return (false);
    if (print_action(info, "is thinking") == false)
		return (false);
	usleep(1000 * info->all_info->time_to_think);
	return (true);
}

bool	sleeping(t_philo *info)
{
	if (info->all_info->philo_die_ornot == true)
		return (false);
	if (print_action(info, "is sleeping") == false)
		return (false);
	usleep(1000 * info->all_info->time_to_sleep);
	return (true);
}

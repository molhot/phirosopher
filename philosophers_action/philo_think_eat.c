/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/16 22:01:56 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void	unlock_rightfork(t_philo *info, int r_f)
{
	pthread_mutex_unlock(&info->all_info->forks[r_f]);
}

void	unlock_leftfork(t_philo *info, int l_f)
{
	pthread_mutex_unlock(&info->all_info->forks[l_f]);
}

bool	error_unlockrightfork(t_philo *info, int r_f)
{
	unlock_rightfork(info, r_f);
	return (false);
}

bool	error_unlockleftfork(t_philo *info, int l_f)
{
	unlock_rightfork(info, l_f);
	return (false);
}

void	unlock_allfork(t_philo *info, int l_f, int r_f)
{
	pthread_mutex_unlock(&info->all_info->forks[r_f]);
	pthread_mutex_unlock(&info->all_info->forks[l_f]);
}

bool	error_unlokallfork(t_philo *info, int l_f, int r_f)
{
	unlock_allfork(info, l_f, r_f);
	return (false);
}

bool	eat_countup(t_philo *info, int num)
{
	if (pthread_mutex_lock(&(info->all_info->status[num])) != 0)
		return (false);
	info->how_eated = info->how_eated + 1;
	pthread_mutex_unlock(&(info->all_info->status[num]));
	pthread_mutex_lock(&(info->all_info->timecheck));
	info->philo_livedstart = getnowtime();
	pthread_mutex_unlock(&(info->all_info->timecheck));
	return (true);
}

bool	eat_drop(t_philo *info, int l_f, int r_f)
{
	if (pthread_mutex_lock(&info->all_info->forks[l_f]) != 0)
		return (false);
	if (print_action(info, "has taken a fork") == false)
		return (error_unlockleftfork(info, l_f));
	if (pthread_mutex_lock(&info->all_info->forks[r_f]) != 0)
		return (error_unlockleftfork(info, l_f));
	if (print_action(info, "has taken a fork") == false)
		return (error_unlokallfork(info, l_f, r_f));
	if (print_action(info, "is eating") == false)
		return (error_unlokallfork(info, l_f, r_f));
	usleep(1000 * (long long)info->all_info->time_to_eat);
	unlock_allfork(info, l_f, r_f);
	if (l_f - r_f != 1)
	{
		if (eat_countup(info, r_f) == false)
			return (false);
	}
	else
	{
		if (eat_countup(info, l_f) == false)
			return (false);
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

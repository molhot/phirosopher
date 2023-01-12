/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/01/12 22:20:35 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

bool	eat_drop(t_allinfo *info, int l_f, int r_f, int i)
{
    if (pthread_mutex_lock(&info->forks[l_f]) != 0)
		return (false);
	if (print_action(info, i, "take left chopstic") == false)
		return (false);
	if (pthread_mutex_lock(&info->forks[r_f]) != 0)
		return (false);
	if (print_action(info, i, "take right chopstic") == false)
		return (false);
	usleep(1000 * (long long)info->time_to_eat);
	if (print_action(info, i, "eating now, mogumogu okayu~~~") == false)
		return (false);
	info->philoinfo[i].how_eated++;
	pthread_mutex_unlock(&info->forks[l_f]);
	if (print_action(info, i, "droped left fork") == false)
		return (false);
	pthread_mutex_unlock(&info->forks[r_f]);
	if (print_action(info, i, "droped right fork") == false)
		return (false);
	return (true);
}

bool	think(t_allinfo *info, int pn)
{
    if (print_action(info, pn, "thinking now ...mmm") == false)
		return (false);
	return (true);
}

bool	sleeping(t_allinfo *info, int pn)
{
    if (print_action(info, pn, "sleeping now ...zzZZ") == false)
		return (false);
	usleep(1000 * (long long)info->time_to_sleep);
	return (true);
}

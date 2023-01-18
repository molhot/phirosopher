/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/18 21:40:34 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

bool	limited_philolife(t_allinfo *info, int pn)
{
	if (eat_drop_even(info, info->philoinfo[pn].fork_info.l_fork, info->philoinfo[pn].fork_info.r_fork, pn) == false)
		return (false);
	if (info->eat_limit != (int)info->philoinfo[pn].how_eated)
	{
		if (sleeping(info, pn) == false)
			return (false);
		if (think(info, pn) == false)
			return (false);
	}
	return (true);
}

bool	no_limited_philolife(t_allinfo *info, int pn)
{
	if (eat_drop_even(info, info->philoinfo[pn].fork_info.l_fork, info->philoinfo[pn].fork_info.r_fork, pn) == false)
		return (false);
	if (sleeping(info, pn) == false)
		return (false);
	if (think(info, pn) == false)
		return (false);
	return (true);
}

void	*philo_func(void *info)
{
	t_allinfo	*info_t;
	int			pn;

	info_t = (t_allinfo *)info;
	pn = info_t->thread_num;
	if (info_t->eat_limit > 0)
	{
		while ((int)info_t->philoinfo[pn].how_eated != info_t->eat_limit && info_t->philo_die_ornot != true)
			limited_philolife(info_t, pn);
		if (info_t->philo_die_ornot == true)
			printf("philo is dead\n");
	}
	else
	{
		while (info_t->philo_die_ornot != true)
			no_limited_philolife(info_t, pn);
		if (info_t->philo_die_ornot == true)
			printf("philo is dead\n");
	}
	printf("philo func ended\n");
    return (NULL);
}
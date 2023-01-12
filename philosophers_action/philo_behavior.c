/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/12 22:21:23 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

bool	limited_philolife(t_allinfo *info, int pn)
{
	if (eat_drop(info, info->philoinfo[pn].fork_info.l_fork, info->philoinfo[pn].fork_info.r_fork, pn) == false)
	{
		printf("eat missed\n");
		return (false);
	}
	if (info->eat_limit != (int)info->philoinfo[pn].how_eated)
	{
		if (sleeping(info, pn) == false)
		{
			printf("missed sleep\n");
			return (false);
		}
		if (think(info, pn) == false)
		{
			printf("missed think\n");
			return (false);
		}
	}
	return (true);
}

bool	no_limited_philolife(t_allinfo *info, int pn)
{
	if (eat_drop(info, info->philoinfo[pn].fork_info.l_fork, info->philoinfo[pn].fork_info.r_fork, pn) == false)
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
	//printf("%d's thread\n", info_t->thread_num);
	//printf("right chopstic num is >%d & left chopstic num is > %d\n", info_t->philoinfo[info_t->thread_num - 1].fork_info.r_fork, info_t->philoinfo[info_t->thread_num - 1].fork_info.l_fork);
	//printf("eat timing is >%d\n", info_t->eat_limit);
	if (info_t->eat_limit > 0)
	{
		//printf("eat timing is >%ld\n", info_t->philoinfo[info_t->thread_num - 1].how_eated);
		while ((int)info_t->philoinfo[info_t->thread_num].how_eated != info_t->eat_limit && info_t->philo_die_ornot != true)
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
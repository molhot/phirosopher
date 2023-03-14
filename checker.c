/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/14 17:26:35 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	if ((getnowtime() - info->philoinfo[philo_num].philo_livedstart) > info->time_to_die)
	{
		if (print_action(&(info->philoinfo[philo_num]), "died") == false)
			return ;
		info->philo_die_ornot = true;
	}
}

bool	check_eatsatisfied(t_allinfo *info, int philonum)
{
	if (info->eat_limit == (int)info->philoinfo[philonum].how_eated)
		return (true);
	return (false);
}

void	*philo_checker(t_allinfo *info)
{
	size_t	philo_num;
	size_t	countup;

	philo_num = 0;
	countup = 0;
	while (1)
	{
		if (info->eat_limit != -1)
		{
			if ((info->philoinfo)[philo_num].correctend == false && check_eatsatisfied(info, philo_num) == true)
			{
				countup++;
				(info->philoinfo)[philo_num].correctend = true;
			}
			if ((int)countup == info->philo_num - 1)
				break ;
		}
		if ((info->philoinfo)[philo_num].correctend == false)
			philo_deathistrue(philo_num, info);
		if (info->philo_die_ornot == true)
			return (NULL);
		philo_num++;
		if ((int)philo_num == info->philo_num)
			philo_num = 0;
		usleep(200);
	}
	return (NULL);
}
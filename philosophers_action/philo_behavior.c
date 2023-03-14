/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/03/14 20:04:20 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void	*limited_philolife_add(void *info_t)
{
	t_philo		*info;

	info = (t_philo*)info_t;
	while ((int)info->how_eated != info->eat_limit)
	{
		if (eat_drop_even(info, info->fork_info.l_fork, info->fork_info.r_fork) == false)
			return (NULL);
		if (info->eat_limit > (int)info->how_eated)
		{
			if (sleeping(info) == false)
				return (NULL);
			if (think(info) == false)
				return (NULL);
		}
	}
	if ((int)info->how_eated == info->eat_limit)
		info->correctend = true;
	return (NULL);
}

void	*limited_philolife_even(void *info_t)
{
	t_philo		*info;

	info = (t_philo*)info_t;
	while ((int)info->how_eated != info->eat_limit)
	{
		if (eat_drop_even(info, info->fork_info.l_fork, info->fork_info.r_fork) == false)
			return (NULL);
		if (info->eat_limit > (int)info->how_eated)
		{
			if (sleeping(info) == false)
				return (NULL);
			if (think(info) == false)
				return (NULL);
		}
	}
	if ((int)info->how_eated == info->eat_limit)
		info->correctend = true;
	return (NULL);
}


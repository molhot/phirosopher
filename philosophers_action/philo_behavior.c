/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/03/14 20:39:25 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void	*philolife_life(void *info_t)
{
	t_philo		*info;

	info = (t_philo*)info_t;
	info->philo_livedstart = getnowtime();
	while ((int)info->how_eated <= info->eat_limit)
	{
		if (eat_drop(info, info->fork_info.l_fork, info->fork_info.r_fork) == false)
			return (NULL);
		if (info->eat_limit > (int)info->how_eated)
		{
			if (sleeping(info) == false)
				return (NULL);
			if (think(info) == false)
				return (NULL);
		}
	}
	return (NULL);
}

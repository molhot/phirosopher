/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/11 22:35:50 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void	*philo_func(void *info)
{
	t_allinfo	*info_t;

	info_t = (t_allinfo *)info;
	printf("%d's thread\n", info_t->thread_num);
    return NULL;
}
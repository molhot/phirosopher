/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2022/12/10 02:15:11 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philosophers.h"

void eat(int eat_time)
{
    usleep(eat_time);
}

void think(int think_time)
{
    usleep(think_time);
}

void sleep(int sleeping_time)
{
    usleep(sleeping_time);
}
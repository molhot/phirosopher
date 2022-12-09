/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2022/12/10 07:16:04 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void insert_philoinfo_to_struct(philo_t* sub_t, char *argv[])
{
	sub_t->number_of_philo = ft_atoi(argv[1]);
	sub_t->time_to_die = ft_atoi(argv[2]);
	sub_t->time_to_eat = ft_atoi(argv[3]);
	sub_t->time_tosleep = ft_atoi(argv[4]);
}

int main(int argc, char *argv[])
{
	philo_t		*philoinfo;
	pthread_t	*handle;

	int			judge;

	judge = 0;
	if (argc < 5)
		judge = print_errormessage(ERROR_ARGUMENTNUM);
	philoinfo = (philo_t *)malloc(sizeof(philo_t) * 1);
	if (philoinfo == NULL)
		judge = print_errormessage(ERROR_MALLOC);
	insert_philoinfo_to_struct(philoinfo, argv);
	handle = (pthread_t *)malloc(sizeof(pthread_t) * philoinfo->number_of_philo);
	if (handle == NULL)
		judge = print_errormessage(ERROR_MALLOC);
	if (judge != 0)
		return (1);
	philo_life(philoinfo, );
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2022/12/09 12:37:00 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void insert_philoinfo_to_struct(philo_t* sub_t, char *argv[])
{
	sub_t->number_of_philo = ft_atoi(argv[1]);
	sub_t->time_to_die = ft_atoi(argv[2]);
	sub_t->time_to_eat = ft_atoi(argv[3]);
	sub_t->time_tosleep = ft_atoi(argv[4]);

	return (sub_t);
}

static void philo_func()
{

}

int main(int argc, char *argv[])
{
	philo_t		*philoinfo;
	size_t		philonum;
	pthread_t	handle;

	if (argc < 5)
	{
		print_errormessage(ERROR_ARGUMENTNUM);
		return (1);
	}
	philoinfo = (philo_t *)malloc(sizeof(philo_t) * 1);
	if (philoinfo == NULL)
	{
		print_errormessage(ERROR_MALLOC);
		return (1);
	}
	insert_philoinfo_to_struct(philoinfo, argv);
	philonum = philoinfo->number_of_philo;
	while (philonum != 0)
	{
		pthread_create(&handle, NULL, philo_func, );
	}
}
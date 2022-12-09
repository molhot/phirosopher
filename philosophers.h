/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:45 by satushi           #+#    #+#             */
/*   Updated: 2022/12/09 20:33:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERES_H
# define PHILOSOPHERES_H

// #ifndef number_of_philosophers
// # define number_of_philosophers 3
// #endif

// #ifndef time_to_die
// # define time_to_die 100
// #endif

// #ifndef time_to_eat
// # define time_to_eat 20
// #endif

// #ifndef time_to_sleep
// # define time_to_sleep 20
// #endif

# define ERROR_ARGUMENTNUM 1
# define ERROR_MALLOC 2

typedef struct philo_info{
	size_t	number_of_philo;
    int		time_to_die;
	int		time_to_eat;
	int		time_tosleep;
}philo_t;

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>

int		print_errormessage(int errornum);
int		ft_atoi(const char *str);


#endif
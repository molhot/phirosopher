/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graspcharlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:24:07 by satushi           #+#    #+#             */
/*   Updated: 2022/12/09 20:27:14 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t grasp_charlen(char *sentence)
{
	size_t	counter;

	counter = 0;
	while (sentence[counter] != '\0')
		counter++;
	
	return (counter);
}
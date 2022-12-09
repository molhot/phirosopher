/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/10 03:15:59 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int print_errormessage(int errornum)
{
	if (errornum == ERROR_ARGUMENTNUM)
		ft_putchar_fd("argnum is difficult\n you must write four argnum\n");
	if (errornum == ERROR_MALLOC)
		ft_putchar_fd("malloc is missed\n");
	return (1);
}

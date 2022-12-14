/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:41 by satushi           #+#    #+#             */
/*   Updated: 2023/01/11 21:02:20 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int print_errormessage(int errornum)
{
	if (errornum == ERROR_ARGUMENT)
		ft_putchar_fd("argnum is difficult\n you must write four argnum\n");
	if (errornum == ERROR_MALLOC)
		ft_putchar_fd("malloc is missed\n");
	return (1);
}

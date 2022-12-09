/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:27 by satushi           #+#    #+#             */
/*   Updated: 2022/12/09 20:26:50 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void ft_putchar_fd(char *error_sentence)
{
	size_t errorsen_len;

	errorsen_len = grasp_charlen(error_sentence);
	write(1, error_sentence, errorsen_len);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_shorterargc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/09 20:20:24 by satushi          ###   ########.fr       */
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

size_t grasp_charlen(char *sentence)
{
	size_t	counter;

	counter = 0;
	while (sentence[counter] != '\0')
		counter++;
	
	return (counter);
}

void ft_putchar_fd(char *error_sentence)
{
	size_t errorsen_len;

	errorsen_len = grasp_charlen(error_sentence);
	write(1, error_sentence, errorsen_len);
}


int print_errormessage(int errornum)
{
	if (errornum == ERROR_ARGUMENTNUM)
		ft_putchar_fd("argnum is difficult\n you must write four argnum\n");
	if (errornum == ERROR_MALLOC)
		ft_putchar_fd("malloc is missed\n");
	return (1);
}

/*
int main()
{
	print_errormessage(ERROR_ARGUMENTNUM);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:50:29 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:47:02 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int	error(void)
{
	ft_putstr_fd("error file not found\n", 1);
	return (-1);
}

int	usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
	return (-1);
}

int	tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

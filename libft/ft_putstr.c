/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:19:47 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/27 21:36:33 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(const char *str)
{
	int		i;

	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

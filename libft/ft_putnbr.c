/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:21:08 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/27 21:35:53 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

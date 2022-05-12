/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:42:41 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/27 21:15:06 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_cptchiffre(long n)
{
	int		i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	ft_moins(long nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	cpt;
	char	*str;
	int		moins;

	nb = n;
	moins = ft_moins(nb);
	cpt = ft_cptchiffre(nb);
	str = ft_strnew(cpt + moins);
	if (!str)
		return (NULL);
	if (moins)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (cpt > 0)
	{
		str[cpt + moins - 1] = (nb % 10) + '0';
		cpt--;
		nb = nb / 10;
	}
	return (str);
}

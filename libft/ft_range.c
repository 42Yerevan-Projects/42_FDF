/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:19:38 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:10:14 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		progressor;
	int		i;

	tab = NULL;
	i = 0;
	progressor = min;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (!tab)
		return (NULL);
	while (progressor < max)
	{
		tab[i] = progressor;
		i++;
		progressor++;
	}
	return (tab);
}

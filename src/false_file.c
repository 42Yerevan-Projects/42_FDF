/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:10:36 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 21:14:23 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	false(char **tab, int i);

int	false_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		false(tab, i);
		i++;
	}
	return (0);
}

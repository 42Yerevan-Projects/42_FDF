/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:34:59 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/06 20:36:00 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all_tab(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < (size_t)env->southmax)
	{
		free(env->tab[i]);
		++i;
	}
	free(env->tab);
	free(env->eastmax);
}

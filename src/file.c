/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:57:04 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/06 20:24:55 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	determine_eastmax(char *line, t_env *env, int south)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (false_tab(tab) == 1)
		return (-1);
	while (tab[i])
		i++;
	env->eastmax[south] = tablen(tab);
	vec_str_del(&tab);
	return (i);
}

void	work_coords(int fd, t_env *env, char *line, int south)
{
	env->tab = (int **)malloc(sizeof(int *) * (env->southmax));
	if (!env->tab)
		exiterror();
	env->eastmax = (int *)malloc(sizeof(int) * (env->southmax));
	if (!env->eastmax)
		exiterror();
	line = NULL;
	south = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if ((determine_eastmax(line, env, south)) == -1)
			exiterror();
		if (south != 0)
			if (env->eastmax[south] != env->eastmax[south - 1])
				exiterror();
		env->tab[south] = assign_all_coords(line);
		if (env->tab[south] == NULL)
			exiterror();
		south++;
		free(line);
	}
	free(line);
	print_map(*env);
}

void	print_map(t_env env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env.southmax)
	{
		ft_putstr(" : ");
		while (j < env.eastmax[i])
		{
			ft_putnbr(env.tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}

int	*assign_all_coords(char *line)
{
	char	**tab;
	int		i;
	int		*oneline;
	int		eastmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	eastmax = tablen(tab);
	oneline = (int *)malloc(sizeof(int) * eastmax);
	if (!oneline)
		return (NULL);
	while (tab[i] && (i < eastmax))
	{
		oneline[i] = ft_atoi(tab[i]);
		i++;
	}
	vec_str_del(&tab);
	return (oneline);
}

int	false(char **tab, int i)
{
	int		j;

	j = 0;
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] == '-')
		{
			j++;
			while (tab[i][j] != '\0')
			{
				if (tab[i][j] < '0' || tab[i][j] > '9')
					return (1);
				j++;
			}
		}
		else if (tab[i][j] >= '0' && tab[i][j] <= '9')
			j++;
		else
			return (1);
	}
	return (0);
}

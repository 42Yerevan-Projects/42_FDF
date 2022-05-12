/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:35:49 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/20 20:31:00 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all_x(t_env *env)
{
	int		i;

	i = 0;
	env->turn = 0;
	while (i < env->southmax)
	{
		while (env->turn < env->eastmax[i] - 1)
		{
			env->x1 = env->view_x + (env->turn - i) * env->linesizex;
			env->y1 = env->view_y + (env->turn + i) * env->linesizey
				- (env->tab[i][env->turn] * env->z);
			env->x2 = env->view_x + ((env->turn + 1) - i) * env->linesizex;
			env->y2 = env->view_y + ((env->turn + 1) + i) * env->linesizey
				- (env->tab[i][env->turn + 1] * env->z);
			bresenham(env);
			env->turn++;
		}
		i++;
		env->turn = 0;
	}
}

void	draw_all_y(t_env *env)
{
	int		i;

	i = 0;
	env->turn = 0;
	while (i < env->southmax - 1)
	{
		while (env->turn < env->eastmax[i])
		{
			env->x1 = env->view_x + (env->turn - i) * env->linesizex;
			env->y1 = env->view_y + (env->turn + i) * env->linesizey
				- (env->tab[i][env->turn] * env->z);
			env->x2 = env->view_x + ((env->turn) - (i + 1)) * env->linesizex;
			env->y2 = env->view_y + ((env->turn) + (i + 1)) * env->linesizey
				- (env->tab[i + 1][env->turn] * env->z);
			bresenham(env);
			env->turn++;
		}
		i++;
		env->turn = 0;
	}
}

void	positive(t_env *env)
{
	int		err;
	int		i;

	i = 0;
	err = env->dx / 2;
	while (i < env->dx)
	{
		env->x1 += env->increase_x;
		err += env->dy;
		if (err > env->dx)
		{
			err -= env->dx;
			env->y1 += env->increase_y;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
		i++;
	}
}

void	negative(t_env *env)
{
	int		err;
	int		i;

	i = 0;
	err = env->dy / 2;
	while (i < env->dy)
	{
		env->y1 += env->increase_y;
		err += env->dx;
		if (err > env->dy)
		{
			err -= env->dy;
			env->x1 += env->increase_x;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
		i++;
	}
}

void	bresenham(t_env *env)
{
	if (env->x2 > env->x1)
		env->increase_x = 1;
	else
		env->increase_x = -1;
	if (env->y2 > env->y1)
		env->increase_y = 1;
	else
		env->increase_y = -1;
	env->dx = abs(env->x2 - env->x1);
	env->dy = abs(env->y2 - env->y1);
	if (env->dx > env->dy)
	{
		positive(env);
	}
	else
	{
		negative(env);
	}
	mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
	mlx_pixel_put(env->mlx, env->win, env->x2, env->y2, env->color);
}

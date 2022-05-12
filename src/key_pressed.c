/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:57:11 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/20 20:31:31 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	left_right_key(int keycode, t_env *env)
{
	printf ("%d\n", keycode);
	if (keycode == 123)
	{
		env->view_x -= 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 124)
	{
		env->view_x += 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

int	move_key(int keycode, t_env *env)
{
	printf ("%d\n", keycode);
	if (keycode == 126)
	{
		env->view_y -= 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 125)
	{
		env->view_y += 100;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

int	colors_key(int keycode, t_env *env)
{
	if (keycode == 11)
	{
		env->color = 0x0000FF;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 15)
	{
		env->color = 0xFF0000;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 5)
	{
		env->color = 0x00FF00;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

int	zoom_key(int keycode, t_env *env)
{
	if (keycode == 257)
	{
		if (env->linesizey > 1)
		{
			env->linesizex = env->linesizex / 2;
			env->linesizey = env->linesizey / 2;
		}
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 258)
	{
		env->linesizex = env->linesizex * 2;
		env->linesizey = env->linesizey * 2;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	return (0);
}

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		env->z++;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 78)
	{
		env->z--;
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	if (keycode == 51)
	{
		init_map(env);
		mlx_clear_window(env->mlx, env->win);
		draw(env);
	}
	move_key(keycode, env);
	left_right_key(keycode, env);
	colors_key(keycode, env);
	zoom_key(keycode, env);
	return (0);
}

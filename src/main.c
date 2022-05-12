/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:57:19 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/20 20:31:38 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_env *env)
{
	draw_all_x(env);
	draw_all_y(env);
}

void	init_map(t_env *env)
{
	env->height = 800;
	env->width = 1200;
	env->color = 0xDFFF00;
	env->linesizex = 32;
	env->linesizey = 16;
	env->z = 3;
	env->view_x = 500;
	env->view_y = 200;
}

void	ft_map(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "FdF");
	draw(env);
	mlx_key_hook(env->win, key_pressed, env);
	mlx_hook(env->win, 17, (1L << 17), red_cross, &env);
	mlx_loop(env->mlx);
}

void	southmax(int fd, t_env *env)
{
	char	*line;
	int		south;

	south = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		south++;
		free(line);
	}
	free(line);
	env->southmax = south;
}

int	main(int argc, char **argv)
{
	t_env		env;
	int			fd;

	fd = 0;
	if (argc != 2)
		return (usage());
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !(ft_check_extension(argv[1], ".fdf")))
		return (error());
	init_map(&env);
	southmax(fd, &env);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !(ft_check_extension(argv[1], ".fdf")))
		return (error());
	work_coords(fd, &env, 0, 0);
	ft_map(&env);
	free_all_tab(&env);
	return (0);
}

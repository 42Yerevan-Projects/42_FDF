/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:45:30 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/20 20:31:21 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_env
{
	void			*mlx;
	void			*win;
	int				z;
	int				width;
	int				height;
	int				linesizex;
	int				linesizey;
	int				southmax;
	int				*eastmax;
	unsigned long	color;
	int				**tab;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				increase_x;
	int				increase_y;
	int				turn;
	int				view_y;
	int				view_x;
}		t_env;

void				draw_all_x(t_env *env);
void				draw_all_y(t_env *env);
int					extension_1(int keycode, t_env *env);
int					extension_2(int keycode, t_env *env);
int					extension_3(int keycode, t_env *env);
void				bresenham(t_env *env);
void				negative(t_env *env);
void				positive(t_env *env);
int					error(void);
int					usage(void);

int					ft_check_extension(char *path, char *ext);
int					red_cross(int keycode, t_env *env);

void				work_coords(int fd, t_env *env, char *line, int south);
int					*assign_all_coords(char *line);
void				vec_str_del(char ***vec);
void				ft_map(t_env *env);
void				draw(t_env *env);
int					false_tab(char **tab);
void				init_map(t_env *env);
int					key_pressed(int keycode, t_env *env);
int					exiterror(void);
int					tablen(char **tab);
void				print_map(t_env env);
void				free_all_tab(t_env *env);
#endif
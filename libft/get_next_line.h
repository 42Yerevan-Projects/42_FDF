/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:23:25 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/06 21:11:55 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2048

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

int		get_next_line(int fd, char **line, int get);
int		ft_strendl(char *str);
char	*ft_getline(char *memory);
char	*ft_clearmemory(char *memory, int i, int j);
int		ft_strlen(const char *s);

#endif

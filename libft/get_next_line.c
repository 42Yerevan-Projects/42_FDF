/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:23:25 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/06 21:12:17 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	ft_strendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *memory, char *buffer)
{
	char	*together;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(memory) + ft_strlen(buffer) + 1;
	together = malloc(sizeof(char) * len);
	if (!together)
		return (NULL);
	i = 0;
	j = 0;
	if (memory)
		while (memory[i] != '\0')
			together[j++] = memory[i++];
	i = 0;
	if (buffer)
		while (buffer[i] != '\0')
			together[j++] = buffer[i++];
	together[len - 1] = '\0';
	free(memory);
	return (together);
}

char	*ft_getline(char *memory)
{
	char	*tmp;
	int		i;

	i = 0;
	while (memory && memory[i] != '\0' && memory[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (memory && memory[i] != '\0' && memory[i] != '\n')
	{
		tmp[i] = memory[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_clearmemory(char *memory, int i, int j)
{
	char	*tmp;
	int		len;

	i = 0;
	if (!memory)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	len = ft_strlen(memory) - i;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (memory[i] != '\0')
		tmp[j++] = memory[i++];
	tmp[j] = '\0';
	free(memory);
	return (tmp);
}

int	get_next_line(int fd, char **line, int get)
{
	char		*buffer;
	static char	*memory;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	get = 1;
	get = read(fd, buffer, BUFFER_SIZE);
	while (get > 0)
	{
		buffer[get] = '\0';
		memory = ft_strjoin(memory, buffer);
		if (ft_strendl(memory))
			break ;
	}
	free(buffer);
	if (get < 0)
		return (-1);
	*line = ft_getline(memory);
	memory = ft_clearmemory(memory, 0, 0);
	if (get == 0 && !memory)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:48:16 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:27:02 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	charriot;

	i = 0;
	str = (char *)s;
	charriot = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == charriot)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

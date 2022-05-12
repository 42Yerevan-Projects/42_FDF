/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:36:53 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:58:07 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	str1 = ((unsigned char *)dest);
	str2 = ((unsigned char *)src);
	while (n > 0)
	{
		n--;
		str1[i] = str2[i];
		if (str1[i] == (unsigned char)c)
			return ((unsigned char *)str1 + i + 1);
		i++;
	}
	return (NULL);
}

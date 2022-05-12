/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:16:48 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:20:41 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	longer;

	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	longer = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (little[longer] != '\0')
		longer++;
	while (big[i] != '\0' && i < len)
	{
		while (little[j] == big[i + j] && i + j < len)
		{
			if (j == longer - 1 && i < len)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

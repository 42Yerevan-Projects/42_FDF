/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:15:46 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:22:22 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (needle[len] != '\0')
		len++;
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (j == len - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

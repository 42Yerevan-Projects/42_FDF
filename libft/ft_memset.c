/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:33:05 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:28:00 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		n--;
		((unsigned char *)s)[n] = (unsigned char)c;
	}
	return (s);
}

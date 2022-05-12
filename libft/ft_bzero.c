/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:45:21 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:58:46 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*chainoct;

	chainoct = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		chainoct[n] = '\0';
	}
}

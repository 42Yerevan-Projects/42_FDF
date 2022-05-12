/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:11:24 by vtorosya          #+#    #+#             */
/*   Updated: 2022/03/06 21:12:07 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int		a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}

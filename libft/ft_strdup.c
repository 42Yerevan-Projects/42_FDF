/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:56:54 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:14:31 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}

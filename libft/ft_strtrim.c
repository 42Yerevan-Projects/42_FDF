/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:06 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 21:07:23 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_len1(char const *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	return (i);
}

char	*ft_strtrim(char const *s, int deb, int fin, char *str)
{
	int		j;

	if (!(s))
		return (NULL);
	deb = 0;
	j = 0;
	fin = ft_len1(s);
	while (s[deb] == '\t' || s[deb] == ' ' || s[deb] == '\n')
		deb++;
	while (s[fin] == '\t' || s[fin] == ' ' || s[fin] == '\n')
		fin--;
	if ((deb > fin) > 0)
		deb = 0;
	str = ft_strnew(fin - deb + 1);
	if (!str)
		return (NULL);
	while (deb <= fin)
	{
		str[j] = s[deb];
		deb++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:19:04 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:13:26 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	if (str1 == str2)
		return (0);
	i = 0;
	while ((str1[i]) && (str2[i]) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

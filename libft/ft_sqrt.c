/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:17:49 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 20:11:34 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		i;
	int		res;
	int		res2;

	i = 1;
	res = 0;
	res2 = 0;
	if (nb == 1)
		return (1);
	while (res2 != nb)
	{
		res = nb / i;
		res2 = res * res;
		i++;
		if (i > nb)
			return (0);
	}
	i--;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:11:58 by vtorosya         #+#    #+#             */
/*   Updated: 2022/02/26 21:13:25 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int		i;
	int		nb;
	int		petittiret;

	i = 0;
	nb = 0;
	petittiret = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		petittiret = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb * petittiret);
}

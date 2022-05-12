/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:57:02 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:57:52 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mylst;

	if (lst)
	{
		while (lst)
		{
			mylst = f(lst);
			mylst->next = ft_lstmap(lst->next, f);
			return (mylst);
		}
	}
	return (NULL);
}

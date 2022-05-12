/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:45:47 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/26 21:57:45 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*prolist;

	list = *alst;
	while (list)
	{
		prolist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = prolist;
	}
	*alst = NULL;
}

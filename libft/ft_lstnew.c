/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:08:21 by vtorosya          #+#    #+#             */
/*   Updated: 2022/02/28 21:04:49 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylst;

	mylst = (t_list *)malloc(sizeof(t_list));
	if (!mylst)
		return (NULL);
	if (content == NULL)
	{
		mylst->content = NULL;
		mylst->content_size = 0;
	}
	else
	{
		mylst->content = malloc(content_size);
		if (!mylst->content)
		{
			free(mylst);
			return (NULL);
		}
		mylst->content = ft_memalloc(content_size);
		mylst->content = ft_memcpy(mylst->content, content, content_size);
		mylst->content_size = content_size;
	}
	mylst->next = NULL;
	return (mylst);
}

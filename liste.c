/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:11:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 02:11:21 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liste.h"

t_liste			*list_new(char *data)
{
	t_liste	*node;

	if (!data)
		return (NULL);
	if (!(node = ft_memalloc(sizeof(t_liste))))
		return (NULL);
	if (!(node->data = ft_memalloc(ft_strlen(data) + 1)))
		return (NULL);
	ft_strcpy(node->data, (const char*)data);
    node->next = NULL;
    return (node);
}



t_liste			*list_clear(t_liste *head)
{
	t_liste	*next;

	next = head;
	while (next)
	{
		next = head->next;
		ft_strdel(&head->data);
		ft_memdel((void **)&head);
	}
	return (NULL);
}
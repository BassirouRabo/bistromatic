/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:11:51 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 02:11:53 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue			*queue_new(char	*data, t_type type)
{
	t_queue	*node;

	if (!data)
		return (NULL);
	if (!(node = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(node->data = ft_memalloc(ft_strlen(data) + 1)))
		return (NULL);
	ft_strcpy(node->data, (const char*)data);
	node->next = NULL;
	node->type = type;
	return (node);
}

t_queue			*queue_enqueue(t_queue *head, t_queue *node)
{
	t_queue *cursor;
	if (!node)
		return (head);
	if (!head)
		return (node);
	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	return (head);
}

t_queue			*queue_dequeue(t_queue *head)
{
	t_queue	*cpy;

	if (!head)
		return (NULL);
	if (!head->next)
	{
		ft_strdel(&head->data);
		ft_memdel((void **)&head);
		return (NULL);
	}
	cpy = head;
	while (head->next->next)
		head = head->next;
	ft_strdel(&head->next->data);
	ft_memdel((void **)head->next);
	return (cpy);
}

void			queue_clear(t_queue *head)
{
	t_queue	*next;

	next = head;
	while (next)
	{
		next = next->next;
		ft_strdel(&head->data);
		ft_memdel((void **)head);
	}
}

void			queue_print(t_queue *head)
{
	while (head)
	{
		ft_putstr(head->data);
		ft_putchar('\n');
		head = head->next;
	}
}

int				queue_len(t_queue *head)
{
	int		i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:11:36 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 12:36:12 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack			*stack_new(char *data, t_type type)
{
	t_stack *node;

	if (!data)
		return (NULL);
	if (!(node = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(node->data = ft_memalloc(ft_strlen(data) + 1)))
		return (NULL);
	ft_strcpy(node->data, (const char*)data);
	node->next = NULL;
	node->type = type;
	return (node);
}

t_stack			*stack_push(t_stack *head, t_stack *node)
{
	t_stack *cursor;

	cursor = head;
	if (!node)
		return (cursor);
	node->next = cursor;
	return (node);
}

t_stack			*stack_pop(t_stack *head)
{
	t_stack *next;

	next = head;
	if (head)
	{
		next = head->next;
		ft_strdel(&head->data);
		ft_memdel((void **)&head);
	}
	return (next);
}

void			stack_print(t_stack *head)
{
	printf("*** STACK ***\n");
	while (head)
	{
		ft_putstr(head->data);
		ft_putchar(' ');
		head = head->next;
	}
	ft_putchar('\n');
	printf("*** STACK END ***\n\n");
}

int				stack_len(t_stack *head)
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

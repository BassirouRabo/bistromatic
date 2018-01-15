/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:41 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 03:01:26 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			ft_parse_token(t_queue **head, char *base, char *in, int size)
{
	int		res;
	int		len;
	t_queue	*cpy;

	init_token(&res, &len);
	if (IS_OPERATOR_1(*in))
	{
		while (in && *in && IS_OPERATOR_1(*in))
			in++;
		if (!set_first_sign(head, base, in))
			return (0);
	}
	while (len < size && in && *in)
		if (!parse_init(head, base, &in, new_nb(&len, &res)))
			return (0);
	cpy = *head;
	while (*head && (*head)->next)
	{
		if (IS_OPEN(*(*head)->data) && ft_strlen((*head)->next->data) == 1
			&& IS_ADD(*(*head)->next->data))
			(*head)->next = (*head)->next->next;
		*head = (*head)->next;
	}
	*head = cpy;
	return (1);
}

int			set_first_sign(t_queue **head, char *base, char *in)
{
	char	*num;
	char	*mul;

	if (IS_ADD(*in))
		return (1);
	if (!(num = ft_memalloc(3)))
		return (0);
	if (!(mul = ft_memalloc(2)))
		return (0);
	num[0] = '-';
	num[1] = base[1];
	num[2] = '\0';
	mul[0] = '*';
	mul[1] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(num, OPERAND))))
		return (0);
	if (!(*head = queue_enqueue(*head, queue_new(mul, OPERATOR_2))))
		return (0);
	return (1);
}

void		init_token(int *res, int *len)
{
	*len = 0;
	*res = 0;
}

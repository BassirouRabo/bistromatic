/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:41 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 07:26:55 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			ft_parse_token(t_queue **head, char *base, char *in, int size)
{
	int		res;
	int		len;

	res = 0;
	len = 0;
	if (is_unary(base, in))
	{
		if (!(res = set_unary_operand(head, base, in)))
			return (0);
		in += res;
		len += res;
	}
	while (len < size && in && *in)
	{
		if (!parse_init(base, &in, head, new_nb(&len, &res)))
			return (0);
	}
	return (1);
}

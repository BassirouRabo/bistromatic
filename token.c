/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 07:08:10 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 01:18:52 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int			parse_init(char *b, char **in, t_queue **head, t_nb *nb)
{
	int		*len;
	int		*res;

	len = nb->len;
	res = nb->res;
	if (IS_OPERAND(b, **in) && !(token_operand(head, b, in, len)))
		return (0);
	else if (IS_OPERATOR_1(**in) && !token_add_sub(head, &*in, &*len))
		return (0);
	else if (IS_OPERATOR_2(**in) && !(token_mul_div_mod(head, b, &*in, &*len)))
		return (0);
	else if ((IS_OPEN(**in) || IS_CLOSE(**in)))
	{
		if (!(*res = set_bracket(head, *in)))
			return (0);
		*in += *res;
		*len += *res;
	}
	return (1);
}

int			token_operand(t_queue **head, char *b, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_operand(head, b, *in, 0)))
		return (0);
	*in += res;
	*len += res;
	return (1);
}

int			token_add_sub(t_queue **head, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_add_sub(head, *in)))
		return (0);
	*in += res;
	*len += res;
	return (1);
}

int			token_mul_div_mod(t_queue **head, char *b, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_mul_div_mod(head, b, *in)))
		return (0);
	*in += res;
	*len += res;
	return (1);
}

int			token_braket(t_queue **head, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_bracket(head, *in)))
		return (0);
	*in += res;
	*len += res;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:41 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 03:59:11 by brabo-hi         ###   ########.fr       */
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
		if (IS_OPERAND(base, *in) && !(token_operand(head, base, &in, &len)))
			return (0);
		else if ((IS_ADD(*in) || IS_SUB(*in)) && !token_add_sub(head, &in, &len))
			return (0);
		else if ((IS_MUL(*in) || IS_DIV(*in) || IS_MOD(*in)) && !(token_mul_div_mod(head, base, &in, &len)))
			return (0);
		else if ((IS_OPEN(*in) || IS_CLOSE(*in)))
		{
			if (!(res = set_bracket(head, in)))
				return (0);
			in += res;
			len += res;
		}
		else
			return (0);
	}
	return (1);
}

int			token_operand(t_queue **head, char *base, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_operand(head, base, *in, 0)))
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

int			token_mul_div_mod(t_queue **head, char *base, char **in, int *len)
{
	int		res;

	res = 0;
	if (!(res = set_mul_div_mod(head, base, *in)))
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
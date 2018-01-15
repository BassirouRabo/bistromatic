/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 05:23:36 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 04:19:18 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int			set_operand(t_queue **head, char *base, char *in, int sign)
{
	char	*data;
	int		i;
	int		len;

	i = 0;
	len = sign ? 1 : 0;
	while (in && in[i] && IS_OPERAND(base, in[i++]))
		len++;
	i = 0;
	if (!(data = ft_memalloc(len + 1)))
		return (0);
	if (sign)
		data[i++] = '-';
	while (i < len)
		data[i++] = *in++;
	data[i] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(data, OPERAND))))
	{
		ft_strdel(&data);
		return (0);
	}
	return (len = sign ? len - 1 : len);
}

int			set_unary(t_queue **head, char *base, char *in)
{
	char	sign;
	int		res;
	int		res_op;

	res = 0;
	sign = get_unary_sign(in);
	res_op = 0;
	while (in && *in && IS_OPERATOR_1(*in))
	{
		res++;
		in++;
	}
	if (IS_OPERAND(base, *in))
	{
		if (!(res_op = set_operand(head, base, in, IS_SUB(sign) ? 1 : 0)))
			return (0);
	}
	else if (IS_OPEN(*in) && !(set_minus(head, base, sign)))
		return (0);
	return (res + res_op);
}

int			set_minus(t_queue **head, char *base, char sign)
{
	char	*plus;
	char	*num;
	char	*mul;
	int		i;

	i = 0;
	if (!(num = ft_memalloc(3)))
		return (0);
	if (!(mul = ft_memalloc(2)))
		return (0);
	if (!(plus = ft_memalloc(2)))
		return (0);
	num[i++] = sign;
	num[i++] = base[1];
	num[i] = '\0';
	mul[0] = '*';
	mul[1] = '\0';
	init_set_minus(plus);
	if (!(*head = queue_enqueue(*head, queue_new(plus, OPERATOR_1))))
		return (0);
	if (!(*head = queue_enqueue(*head, queue_new(num, OPERAND))))
		return (0);
	if (!(*head = queue_enqueue(*head, queue_new(mul, OPERATOR_2))))
		return (0);
	return (++i);
}

int			set_mul_div_mod(t_queue **head, char *base, char *in)
{
	char	*data;
	int		i;
	int		res;

	i = 1;
	res = 0;
	data = NULL;
	if (!(data = ft_memalloc(i + 1)))
		return (0);
	data[0] = *in++;
	data[1] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(data, OPERATOR_2))))
	{
		ft_strdel(&data);
		return (0);
	}
	if (in && *in && (IS_OPERATOR_1(*in)))
	{
		if (!(res = set_unary(head, base, in)))
			return (0);
	}
	return (++res);
}

int			set_bracket(t_queue **head, char *base, char *in)
{
	char	*data;
	int		res;

	res = 0;
	if (!(data = ft_memalloc(2)))
		return (0);
	data[0] = *in++;
	data[1] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(data, BRACKET))))
	{
		ft_strdel(&data);
		return (0);
	}
	if (in && *in && (IS_OPERATOR_1(*in)))
	{
		while (in && *in && IS_OPERATOR_1(*in) && res++)
			in++;
		if (!set_minus(head, base, get_unary_sign(in)))
			return (0);
	}
	return (++res);
}

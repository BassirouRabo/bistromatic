/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 05:23:36 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 11:12:53 by brabo-hi         ###   ########.fr       */
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

int			set_unary_operand(t_queue **head, char *base, char *in)
{
	char	sign;
	int		res;
	int		res_operand;
	
	res = 0;
	sign = get_unary_sign(in);
	
	while (in && *in && !IS_OPERAND(base, *in))
	{
		if (IS_OPEN(*in))
		{
			if (!(set_bracket(head, in)))
				return (0);	
		}
		res++;
		in++;
	}
	if (!(res_operand = set_operand(head, base, in, IS_SUB(sign) ? 1 : 0)))
		return (0);	
	return (res + res_operand);
}

int			set_add_sub(t_queue **head, char *in)
{
	int		len;
	char	*data;

	len = 0;
	if (!(data = ft_memalloc(2)))
		return (0);
	data[0] = get_unary_sign(in);
	data[1] = '\0';
	while (in && *in && (IS_OPERATOR_1(*in) || IS_OPEN(*in)))
	{
		if (IS_OPEN(*in))
		{
			if (!(set_bracket(head, in)))
				return (0);	
		}
		in++;
		len++;
	}
	if (!(*head = queue_enqueue(*head, queue_new(data, OPERATOR_1))))
	{
		ft_strdel(&data);
		return (0);
	}
	return (len);
}

int			set_mul_div_mod(t_queue **head, char *base, char *in)
{
	char	*data;
	int		i;
	int		res;
	
	i = 1;
	res = 0;
	if (!(data = ft_memalloc(i + 1)))
		return (0);
	data[0] = *in++;
	data[1] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(data, OPERATOR_2))))
	{
		ft_strdel(&data);
		return (0);
	}
	if (in && *in && (IS_OPERATOR_1(*in) || IS_OPEN(*in)))
	{
		if (!(res = set_unary_operand(head, base, in)))
			return (0);
	}
	return (++res);
}

int			set_bracket(t_queue **head, char *in)
{
	char	*data;

	if (!(data = ft_memalloc(2)))
		return (0);
	data[0] = *in;
	data[1] = '\0';
	if (!(*head = queue_enqueue(*head, queue_new(data, BRACKET))))
	{
		ft_strdel(&data);
		return (0);
	}
	return (1);
}
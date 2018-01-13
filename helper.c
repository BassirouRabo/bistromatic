/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:42 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:20:41 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char		get_sign(char *in)
{
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	while (in && in[i] && IS_OPERATOR_1(in[i]))
	{
		if (IS_SUB(in[i]))
			sign++;
		i++;
	}
	return (sign % 2 ? '-' : '+');
}

int			get_indice(char *base, char c)
{
	int		sign;
	int	i;

	i = 0;
	sign = 0;
	while (base && base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char		get_unary_sign(char *in)
{
	int		sign;
	sign = 0;
	while (in && *in && (IS_OPERATOR_1(*in) || IS_OPEN(*in)) )
	{
		if (IS_SUB(*in))
			sign++;
		in++;
	}
	return (sign % 2 ? '-' : '+');
}

int			is_unary(char *base, char *in)
{
	while (in && !IS_OPERAND(base, *in))
	{
		if (in && IS_OPERATOR_1(*in))
				return (1);
		in++;
	}
	return (0);
}

int			get_power(int n)
{
	int	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res == 1 ? 0 : res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 03:06:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 04:02:16 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void		init_set_minus(char *plus)
{
	plus[0] = '+';
	plus[1] = '\0';
}

int			set_add_sub(t_queue **head, char *base, char *in)
{
	char	sign;
	int		len;
	char	*data;
	int		res_op;

	res_op = 0;
	sign = get_unary_sign(in);
	if (!init_set_add_sub(data, sign, &len))
		return (0);
	while (in && *in && (IS_OPERATOR_1(*in) && in++))
		len++;
	if (IS_OPEN(*in))
	{
		if (!(set_minus(head, base, in, sign)))
			return (0);
	}
	else
	{
		if (!(*head = queue_enqueue(*head, queue_new(data, OPERATOR_1))))
		{
			ft_strdel(&data);
			return (0);
		}
	}
	return (len + res_op);
}

int			init_set_add_sub(char *data, char sign, int *len)
{
	*len = 0;
	if (!(data = ft_memalloc(2)))
		return (0);
	data[0] = sign;
	data[1] = '\0';
	return (1);
}

void		init_parse_init(int **len, int **res, t_nb *nb)
{
	*len = nb->len;
	*res = nb->res;
}

char		*init_multiply(int carry, char *out, int j)
{
	if (carry)
		out[j++] = *ft_itoa(carry);
	out[j] = '\0';
	return (ft_strrev(out));
}
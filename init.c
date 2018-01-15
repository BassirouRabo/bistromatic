/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 03:06:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 05:11:52 by brabo-hi         ###   ########.fr       */
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
	data = NULL;
	len = 0;
	sign = get_unary_sign(in);
	if (!(data = init_data_sign(sign)))
		return (0);
	while (in && *in && (IS_OPERATOR_1(*in) && in++))
		len++;
	if (IS_OPEN(*in))
	{
		if (!(set_minus(head, base, sign)))
			return (0);
	}
	else if (!(*head = queue_enqueue(*head, queue_new(data, OPERATOR_1))))
	{
		ft_strdel(&data);
		return (0);
	}
	return (len + res_op);
}

char		*init_data_sign(char sign)
{
	char	*data;

	if (!(data = ft_memalloc(2)))
		return (NULL);
	data[0] = sign;
	data[1] = '\0';
	return (data);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 07:08:10 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 15:14:24 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int			parse_init( t_queue **head, char *b, char **in, t_nb *nb)
{
	int		*len;
	int		*res;

	len = nb->len;
	res = nb->res;
	//printf("in 0[%s]\n", *in);
	if (IS_OPERAND(b, **in))
	{
		//	printf("IS_OPERAND 0[%s]\n", *in);
		if ( !(token_operand(head, b, in, len)))
			return (0);
		//	printf("IS_OPERAND 1[%s]\n", *in);
	}	
	else if (IS_OPERATOR_1(**in))
	{
	//	printf("IS_OPERATOR_1 0[%s]\n", *in);
		if (!token_add_sub(head, b, &*in, &*len))
			return (0);
	//	printf("IS_OPERATOR_1 1[%s]\n", *in);
	}
	else if (IS_OPERATOR_2(**in))
	{
	//	printf("IS_OPERATOR_2 0[%s]\n", *in);
		if (!(token_mul_div_mod(head, b, &*in, &*len)))
			return (0);
	//	printf("IS_OPERATOR_2 0[%s]\n", *in);
	}
	else if ((IS_OPEN(**in) || IS_CLOSE(**in)))
	{
		//	printf("IS_OPEN -IS_CLOSE  0[%s]\n", *in);
		if (!(token_braket(head, b, &*in, &*len)))
			return (0);
		//	printf("IS_OPEN -IS_CLOSE  1[%s]\n", *in);
	}
//	printf("in 1[%s]\n", *in);
	return (1);
}

int			token_operand(t_queue **head, char *b, char **in, int *len)
{
	int		res;
//	printf("token_operand\n");
	res = 0;
	if (!(res = set_operand(head, b, *in, 0)))
		return (0);
	*in += res;
	*len += res;
	return (1);
}

int			token_add_sub(t_queue **head, char *b, char **in, int *len)
{
	int		res;
//	printf("token_add_sub 0[%s]\n", *in);
	res = 0;
	if (!(res = set_add_sub(head, b, *in)))
		return (0);
	*in += res;
	*len += res;
//	printf("token_add_sub 1[%s]\n", *in);
	return (1);
}

int			token_mul_div_mod(t_queue **head, char *b, char **in, int *len)
{
	int		res;
//	printf("token_mul_div_mod 0[%s]\n", *in);
	res = 0;
	if (!(res = set_mul_div_mod(head, b, *in)))
		return (0);
	*in += res;
	*len += res;
//	printf("token_mul_div_mod 1[%s]\n", *in);
	return (1);
}

int			token_braket(t_queue **head, char *b, char **in, int *len)
{
	int		res;
//	printf("token_braket 0[%s]\n", *in);
	res = 0;
	if (!(res = set_bracket(head, b, *in)))
		return (0);
	*in += res;
	*len += res;
//	printf("token_braket 1[%s]\n", *in);
	return (1);
}

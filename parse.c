/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:41 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:50:14 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			ft_parse_rpn(t_queue *rpn)
{
	return (1);
}

int			ft_parse_shunting(t_queue **rpn, t_queue *tokens)
{
	t_stack	*stack;

	stack = NULL;
	while (tokens)
	{
		if (tokens->type == OPERAND)
			if (!(*rpn = queue_enqueue(*rpn, queue_new(tokens->data, tokens->type))))
				return (0);
		if (tokens->type == OPERATOR_2)
			if (!(stack = stack_push(stack, stack_new(tokens->data, tokens->type))))
				return (0);
		if (tokens->type == OPERATOR_1)
		{
			while (stack && stack->type == OPERATOR_2)
			{
				if (!(*rpn = queue_enqueue(*rpn, queue_new(stack->data, stack->type))))
					return (0);
				if (!(stack = stack_pop(stack)))
					return (0);
			}
			if (!(stack = stack_push(stack, stack_new(tokens->data, tokens->type))))
				return (0);
		}
		if (tokens->type == BRACKET)
		{
			
			if (*tokens->data == OPEN)
			{
				if (!(stack = stack_push(stack, stack_new(tokens->data, tokens->type))))
				return (0);
			}
			if (*tokens->data == CLOSE)
			{
				while (stack && *stack->data != OPEN)
				{
					if (!(*rpn = queue_enqueue(*rpn, queue_new(stack->data, stack->type))))
						return (0);
					stack = stack_pop(stack);
				}		
				if (!stack || *stack->data != OPEN)
					return (0);
				stack = stack_pop(stack);
			}
		}
		tokens = tokens->next;
	}
	while (stack)
	{
		if (!(*rpn = queue_enqueue(*rpn, queue_new(stack->data, stack->type))))
			return (0);
		stack = stack_pop(stack);
	}
	return (validate_rpn(*rpn));
}

int			ft_parse_token(t_queue **head, char *base, char *in)
{
	int		res;
	int		len;
	int		size;

	res = 0;
	len = 0;
//	printf("in [%s]\n", in);
	size = ft_strlen(in);
	if (is_unary(base, in))
	{
		if (!(res = set_unary_operand(head, base, in)))
			return (0);
		in += res;
		len += res;
	}
	while (len < size && in && *in)
	{
		if (IS_OPERAND(base, *in))
		{
		//	printf("IS_OPERAND [%s]\n", in);
			if (!(res = set_operand(head, base, in, 0)))
				return (0);
			in += res;
			len += res;
		//	printf("IS_OPERAND END [%s]\n", in);
		}
		else if (IS_ADD(*in) || IS_SUB(*in))
		{
		//	printf("IS_ADD [%s]\n", in);
			if (!(res = set_add_sub(head, in)))
				return (0);
			in += res;
			len += res;
		//	printf("IS_ADD END [%s]\n", in);
		}
		else if (IS_MUL(*in) || IS_DIV(*in) || IS_MOD(*in))
		{
	//		printf("IS_MUL [%s]\n", in);
			if (!(res = set_mul_div_mod(head, base, in)))
				return (0);
			in += res;
			len += res;
 //			printf("IS_MUL END [%s] [%d]\n", in, res);
		}
		else if (IS_OPEN(*in) || IS_CLOSE(*in))
		{
//			printf("IS_OPEN [%s]\n", in);
			if (!(res = set_bracket(head, in)))
				return (0);
			in += res;
			len += res;
//			printf("IS_OPEN END [%s]\n", in);
		}
		else
			return (0);
	}
	queue_print(*head);
	return (1);
}
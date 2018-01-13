/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:37:41 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:31:18 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			ft_parse_shunting(t_queue **rpn, t_queue *tk)
{
	t_stack	*stack;

	stack = NULL;
	while (tk)
	{
		if (tk->type == OPERAND)
			if (!(*rpn = queue_enqueue(*rpn, queue_new(tk->data, tk->type))))
				return (0);
		if (tk->type == OPERATOR_2)
			if (!(stack = stack_push(stack, stack_new(tk->data, tk->type))))
				return (0);
		if (tk->type == OPERATOR_1)
		{
			while (stack && stack->type == OPERATOR_2)
			{
				if (!(*rpn = queue_enqueue(*rpn,
								queue_new(stack->data, stack->type))))
					return (0);
				if (!(stack = stack_pop(stack)))
					return (0);
			}
			if (!(stack = stack_push(stack, stack_new(tk->data, tk->type))))
				return (0);
		}
		if (tk->type == BRACKET)
		{
			if (*tk->data == OPEN)
			{
				if (!(stack = stack_push(stack,
								stack_new(tk->data, tk->type))))
					return (0);
			}
			if (*tk->data == CLOSE)
			{
				while (stack && *stack->data != OPEN)
				{
					if (!(*rpn = queue_enqueue(*rpn,
									queue_new(stack->data, stack->type))))
						return (0);
					stack = stack_pop(stack);
				}
				if (!stack || *stack->data != OPEN)
					return (0);
				stack = stack_pop(stack);
			}
		}
		tk = tk->next;
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
			if (!(res = set_operand(head, base, in, 0)))
				return (0);
			in += res;
			len += res;
		}
		else if (IS_ADD(*in) || IS_SUB(*in))
		{
			if (!(res = set_add_sub(head, in)))
				return (0);
			in += res;
			len += res;
		}
		else if (IS_MUL(*in) || IS_DIV(*in) || IS_MOD(*in))
		{
			if (!(res = set_mul_div_mod(head, base, in)))
				return (0);
			in += res;
			len += res;
		}
		else if (IS_OPEN(*in) || IS_CLOSE(*in))
		{
			if (!(res = set_bracket(head, in)))
				return (0);
			in += res;
			len += res;
		}
		else
			return (0);
	}
	queue_print(*head);
	return (1);
}

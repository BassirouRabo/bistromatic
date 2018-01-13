/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:55:10 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 03:28:54 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shunting.h"

int			ft_shunting(t_queue **rpn, t_queue *tk)
{
	t_stack	*stack;

	stack = NULL;
	while (tk)
	{
		if (tk->type == OPERAND && !(shunting_operand(rpn, tk)))
			return (0);
		if (tk->type == OPERATOR_2 && !(shunting_operator_2(rpn, tk, &stack)))
			return (0);
		if (tk->type == OPERATOR_1 && !(shunting_operator_1(rpn, tk, &stack)))
			return (0);
		if (tk->type == BRACKET && !(shunting_bracket(rpn, tk, &stack)))
			return (0);
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

int			shunting_operand(t_queue **rpn, t_queue *tk)
{
	if (!(*rpn = queue_enqueue(*rpn, queue_new(tk->data, tk->type))))
		return (0);
	return (1);
}

int			shunting_operator_2(t_queue **rpn, t_queue *tk, t_stack **stack)
{
	if (!(*stack = stack_push(*stack, stack_new(tk->data, tk->type))))
		return (0);
	return (1);
}

int			shunting_operator_1(t_queue **rpn, t_queue *tk, t_stack **stack)
{
	while (stack && *stack && (*stack)->type == OPERATOR_2)
	{
		if (!(*rpn = queue_enqueue(*rpn,
						queue_new((*stack)->data, (*stack)->type))))
			return (0);
		if (!(*stack = stack_pop(*stack)))
			return (0);
	}
	if (!(*stack = stack_push(*stack, stack_new(tk->data, tk->type))))
		return (0);
	return (1);
}

int			shunting_bracket(t_queue **rpn, t_queue *tk, t_stack **stack)
{
	if (*tk->data == OPEN)
	{
		if (!(*stack = stack_push(*stack, stack_new(tk->data, tk->type))))
			return (0);
	}
	if (*tk->data == CLOSE)
	{
		while (*stack && *(*stack)->data != OPEN)
		{
			if (!(*rpn = queue_enqueue(*rpn,
							queue_new((*stack)->data, (*stack)->type))))
				return (0);
			*stack = stack_pop(*stack);
		}
		if (!*stack || *(*stack)->data != OPEN)
			return (0);
		*stack = stack_pop(*stack);
	}
	return (1);
}

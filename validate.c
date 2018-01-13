/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:07:40 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:46:11 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_c(char *base, char *input)
{
	int	i = 0;	
	while (input && *input)
	{
		if (!(IS_VALID(base, *input)))
			return (0);
		input++;
	}
	return (1);
}

int		validate_start_end(char *base, char *input)
{
	if (input && !IS_START(base, *input))
		return (0);
	if (input && !IS_END(base, input[ft_strlen(input) - 1]))
		return (0);
	return (1);
}

int		validate_next(char *base, char *input)
{
	while (input && *input)
	{
		if (IS_OPERAND(base, *input) && input++ && !NEXT_OPERAND(base, *input))
			return (0);
		if (IS_ADD(*input) && input++ && !NEXT_ADD(base, *input))
			return (0);
		if (IS_SUB(*input) && input++ && !NEXT_SUB(base, *input))
			return (0);
		if (IS_ADD(*input) && input++ && !NEXT_ADD(base, *input))
			return (0);
		if (IS_MUL(*input) && input++ && !NEXT_MUL(base, *input))
			return (0);
		if (IS_DIV(*input) && input++ && !NEXT_DIV(base, *input))
			return (0);
		if (IS_MOD(*input) && input++ && !NEXT_MOD(base, *input))
			return (0);
		if (IS_OPEN(*input) && input++ && !NEXT_OPEN(base, *input))
			return (0);
		if (IS_CLOSE(*input) && input++ && !NEXT_CLOSE(base, *input))
			return (0);
		input++;
	}
	return (1);
}

int		valide_balance(char	*input)
{
	int	open;
	int	close;

	open = 0;
	close = 0;
	while (input && *input)
	{
		if (IS_OPEN(*input))
			open++;
		if (IS_CLOSE(*input))
			close++;
		input++;
	}
	return (open == close);
}

int		validate_rpn(t_queue *rpn)
{
	int	operands;
	int	operators;

	operands = 0;
	operators = 0;
	if (rpn && queue_len(rpn) == 1 && rpn->type == OPERAND)
		return (1);
	if (rpn && queue_len(rpn) == 1 && rpn->type != OPERAND)
		return (0);
	while (rpn)
	{
		if (rpn->type == OPERAND)
			operands++;
		if (rpn->type == OPERATOR_1 || rpn->type == OPERATOR_2)
			operators++;
		rpn = rpn->next;
	}
	return (operands - 1 == operators);
}
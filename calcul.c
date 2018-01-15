/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:59:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 04:06:51 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calcul.h"

char		*ft_calculate(t_queue *rpn, char *base)
{
	t_stack	*stack;
	char	*result;

	result = NULL;
	stack = NULL;
	while (rpn)
	{
		if (rpn->type == OPERAND)
		{
			if (!(stack = stack_push(stack, stack_new(rpn->data, OPERAND))))
				return (NULL);
		}
		else
		{
			if (!(result = call_operation(&stack, base, *rpn->data)))
				return (NULL);
			if (!(stack = stack_push(stack, stack_new(result, OPERAND))))
				return (NULL);
		}
		rpn = rpn->next;
	}
	return (result);
}

char		*call_operation(t_stack **stack, char *base, char type)
{
	char	*num1;
	char	*num2;

	num1 = NULL;
	num2 = NULL;
	if (!stack)
		return (NULL);
	num2 = copy((*stack)->data);
	if (!(*stack = stack_pop(*stack)))
		return (NULL);
	num1 = copy((*stack)->data);
	*stack = stack_pop(*stack);
	if (IS_ADD(type))
		return (operate_addition(base, num1, num2));
	if (IS_SUB(type))
		return (operate_substraction(base, num1, num2));
	if (IS_MUL(type))
		return (operate_multiplication(base, num1, num2));
	if (IS_DIV(type))
		return (operate_division(base, num1, num2));
	if (IS_MOD(type))
		return (operate_modulos(base, num1, num2));
	return (NULL);
}

char		*multiply(char *base, char *num1, char num2)
{
	char	*out;
	int		i;
	int		j;
	int		carry;
	int		mul;

	if ((carry = 0) && (!num1 || !num2))
		return ("");
	j = 0;
	i = ft_strlen(num1) - 1;
	out = ft_memalloc((i * 2) + 1);
	while ((size_t)j < ft_strlen(num1))
	{
		mul = carry + ((num1[i] - '0') * (num2 - '0'));
		if ((size_t)mul >= ft_strlen(base))
		{
			out[j] = *ft_itoa(mul % ft_strlen(base));
			carry = mul / ft_strlen(base);
		}
		else
		{
			out[j] = *ft_itoa(mul);
			carry = base[0] - '0';
		}
		i--;
		j++;
	}
	return (init_multiply(carry, out, j));
}

char		*negative_complement(char *base, char *str)
{
	char	*num1;
	char	*num2;
	int		i;

	i = 0;
	if (!(num1 = ft_memalloc(ft_strlen(str + 2))))
		return (NULL);
	if (!(num2 = ft_memalloc(ft_strlen(str + 2))))
		return (NULL);
	num1[i] = base[1];
	num2[i++] = base[0];
	while (str && *str)
	{
		num1[i] = base[0];
		num2[i++] = *str++;
	}
	num1[i] = '\0';
	num2[i] = '\0';
	return (add_negative(substraction(base, num1, num2)));
}

char		*operation_addition_zero(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (addition(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return ("0");
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (add_negative(addition(base, ++num1, ++num2)));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return ("0");
	return (NULL);
}

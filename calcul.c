/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:59:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 11:18:48 by brabo-hi         ###   ########.fr       */
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
	num1 = copy((*stack)->data);
	 if (!(*stack = stack_pop(*stack)))
	 	return (NULL);
	num2 = copy((*stack)->data);
	
	*stack = stack_pop(*stack);
	if (IS_ADD(type))
		return (operate_addition(base, num2, num1));
	if (IS_SUB(type))
		return (operate_substraction(base, num2, num1));
	if (IS_MUL(type))
		return (operate_multiplication(base, num2, num1));
	if (IS_DIV(type))
		return (operate_division(base, num2, num1));
	if (IS_MOD(type))
		return (operate_modulos(base, num2, num1));
	return (NULL);
}

char		*multiply(char *base, char *num1, char num2)
{
	char	*out;
	int		i;
	int		j;
	int		carry;
	int		mul;
	
	carry = 0;
	j = 0;
	if (!num1 || !num2)
		return ("");
	i = ft_strlen(num1) - 1;
	if (!(out = ft_memalloc((i * 2) + 1)))
		return (NULL);	
	while (j < ft_strlen(num1))
	{
		mul = carry + ((num1[i] - '0') * (num2 - '0'));
		if (mul >= ft_strlen(base))
		{
			out[j] = *ft_itoa(mul % 10);
			carry = mul / 10;
		}
		else
		{
			out[j] = *ft_itoa(mul);
			carry = base[0] - '0';
		}
		i--;
		j++;
	}
	if (carry)
		out[j++] = *ft_itoa(carry);
	out[j] = '\0';
	return (ft_strrev(out));
}

char		*negative_complement(char *base, char *str)
{
	char	*num1;
	char	*num2;
	int		i;

	i = 0;
	if (!(num1 = ft_memalloc(ft_strlen(str + 2))) || !(num2 = ft_memalloc(ft_strlen(str + 2))))
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
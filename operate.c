/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:00:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 15:13:44 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

char			*operate_addition(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	int		cmp;
//	printf("Add[%s] [%s]\n", num1, num2);
	init_sign(&num1, &num2, &sign1, &sign2);
//	printf("Add[%s] [%s]\n", num1, num2);
	if (!(cmp = compare(base, num1, num2)))
		return (operation_addition_zero(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (addition(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (substraction(base, num1, num2));
	if (cmp > 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(addition(base, num1, num2)));
	if (cmp > 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(substraction(base, num1, num2)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (addition(base, num1, num2));
	if (cmp < 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (add_negative(substraction(base, num2, num1)));
	if (cmp < 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(addition(base, num1, num2)));
	if (cmp < 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (substraction(base, num2, num1));
	return (NULL);
}

char			*operate_substraction(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	int		cmp;
//	printf("Sub[%s] [%s] 0 \n", num1, num2);
	init_sign(&num1, &num2, &sign1, &sign2);
//	printf("Sub[%s] [%s] 1 \n", num1, num2);

	if (!(cmp = compare(base, num1, num2)))
		return ("0");
	if (cmp > 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (substraction(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (addition(base, num1, num2));
	if (cmp > 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(substraction(base, num1, num2)));
	if (cmp > 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(addition(base, num1, num2)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (add_negative(substraction(base, num2, num1)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (addition(base, num1, num2));
	if (cmp < 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (substraction(base, num2, num1));
	if (cmp < 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(addition(base, num1, num2)));
	return (NULL);
}

char			*operate_multiplication(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;

//	printf("Mul[%s] [%s]\n", num1, num2);
	init_sign(&num1, &num2, &sign1, &sign2);
//	printf("Mul[%s] [%s]\n", num1, num2);
	if (!num1 || !num2 || *num1 == base[0] || *num2 == base[0])
		return (base_first(base));
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (multiplication(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (add_negative(multiplication(base, num1, num2)));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (multiplication(base, num1, num2));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(multiplication(base, num1, num2)));
	return (NULL);
}

char			*operate_division(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;

//	printf("Div[%s] [%s]\n", num1, num2);
	init_sign(&num1, &num2, &sign1, &sign2);
//	printf("Div[%s] [%s]\n", num1, num2);
	if (!num1 || !num2 || *num1 == base[0] || *num2 == base[0])
		return (base_first(base));
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (division(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (add_negative(division(base, num1, num2)));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (division(base, num1, num2));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(division(base, num1, num2)));
	return (NULL);
}

char			*operate_modulos(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;

//	printf("Mod[%s] [%s] 0 \n", num1, num2);
	init_sign(&num1, &num2, &sign1, &sign2);
//	printf("Mod[%s] [%s] [%c] [%c] 0 \n", num1, num2, sign1, sign2);
	if (!num1 || !num2 || *num1 == base[0] || *num2 == base[0])
		return (base_first(base));
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (modulos(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (modulos(base, num1, num2));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (add_negative(modulos(base, num1, num2)));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(modulos(base, num1, num2)));
	return (NULL);
}

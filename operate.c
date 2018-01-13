/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:00:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:27:38 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

char			*operate_addition(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	int		cmp;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (!(cmp = compare(base, num1, num2)))
		return (operation_addition_zero(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (addition(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (substraction(base, num1, ++num2));
	if (cmp > 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(addition(base, ++num1, ++num2)));
	if (cmp > 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(substraction(base, ++num1, num2)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (addition(base, num1, num2));
	if (cmp < 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (add_negative(substraction(base, ++num2, num1)));
	if (cmp < 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(addition(base, ++num1, ++num2)));
	if (cmp < 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(substraction(base, num2, ++num1)));
	return (NULL);
}

char			*operate_substraction(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	int		cmp;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (!(cmp = compare(base, num1, num2)))
		return ("0");
	if (cmp > 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (substraction(base, num1, num2));
	if (cmp > 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (addition(base, num1, ++num2));
	if (cmp > 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (add_negative(substraction(base, ++num1, ++num2)));
	if (cmp > 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(addition(base, ++num1, num2)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_ADD(sign2)))
		return (add_negative(substraction(base, num2, num1)));
	if (cmp < 0 && (IS_ADD(sign1) && IS_SUB(sign2)))
		return (addition(base, num1, ++num2));
	if (cmp < 0 && (IS_SUB(sign1) && IS_SUB(sign2)))
		return (substraction(base, ++num2, ++num1));
	if (cmp < 0 && (IS_SUB(sign1) && IS_ADD(sign2)))
		return (add_negative(addition(base, ++num1, num2)));
	return (NULL);
}

char			*operate_multiplication(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	char	*out;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (multiplication(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (add_negative(multiplication(base, num1, ++num2)));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (multiplication(base, ++num1, ++num2));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(multiplication(base, ++num1, num2)));
	return (NULL);
}

char			*operate_division(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	char	*out;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (division(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (add_negative(division(base, num1, ++num2)));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (division(base, ++num1, ++num2));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(division(base, ++num1, num2)));
	return (NULL);
}

char			*operate_modulos(char *base, char *num1, char *num2)
{
	char	sign1;
	char	sign2;
	char	*out;

	sign1 = IS_SUB(*num1) ? '-' : '+';
	sign2 = IS_SUB(*num2) ? '-' : '+';
	if (IS_ADD(sign1) && IS_ADD(sign2))
		return (modulos(base, num1, num2));
	if (IS_ADD(sign1) && IS_SUB(sign2))
		return (add_negative(modulos(base, num1, ++num2)));
	if (IS_SUB(sign1) && IS_SUB(sign2))
		return (modulos(base, ++num1, ++num2));
	if (IS_SUB(sign1) && IS_ADD(sign2))
		return (add_negative(modulos(base, ++num1, num2)));
	return (NULL);
}

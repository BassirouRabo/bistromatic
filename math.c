/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:44:50 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 12:39:35 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

char		*substraction(char *base, char *num1, char *num2)
{
	char	*out;
	int		i;
	int		j;
	int		len;
	int		borrow;

	borrow = 0;
	j = 0;
	num1 = add_zero_left(num2, num1);
	num2 = add_zero_left(num1, num2);
	i = ft_strlen(num1) - 1;
	if (!(out = ft_memalloc(i + 3)))
		return (NULL);
	out[i + 1] = '\0';
	while (j < ft_strlen(num1))
	{
		if (num1[i] >= num2[i])
		{
			out[j] = *ft_itoa((num1[i] - '0') - (num2[i] - '0') - borrow);
			borrow = 0;
		}
		else
		{
			out[j] = *ft_itoa(((num1[i] - '0') + 10) - (num2[i] - '0')    - borrow);
			borrow = 1;
		}
		i--;
		j++;
	}
	out[j] = '\0';
	if (!ft_strcmp((const char *)num1, (const char *)num2))
		return (out);
	out = ft_strrev(out);
	if (borrow)
		return (negative_complement(base, out));
	while (out && *out == base[0])
		out++;
	return (out);
}

char		*division(char *base, char *num1, char *num2)
{
	int		cmp;
	char	*tmp;
	char	*cpy_num2;
	int		n_tm;
	int		n_sq;

	n_tm = 0;
	n_sq = 0;
	cpy_num2 = num2;
	cmp = compare(base, num1, num2);
	if (cmp < 0)
		return ("0");
	if (cmp == 0)
		return ("1");
	while (ft_strlen(num2) < ft_strlen(num1) - 1)
	{
		n_tm++;
		num2 = multiplication(base, num2, ft_itoa(ft_strlen(base))); 
	}
	n_tm = get_power(n_tm);
	tmp = num2;
	if (compare(base, num1, addition(base, num2, tmp)) >= 0)
		n_sq++;
	while ((cmp = compare(base, num1, addition(base, num2, tmp))) >= 0)
	{
		n_sq++;
		num2 = addition(base, num2, tmp);
	}
	n_tm = n_tm ? n_tm * n_sq : n_sq;
		while ((cmp = compare(base, num1, addition(base, num2, cpy_num2))) >= 0)
	{
		n_tm++;
		num2 = addition(base, num2, cpy_num2);
	}
	// Handle repcision
	return (ft_itoa(n_tm));	
}

char		*addition(char *base, char *num1, char *num2)
{
	char	*out;
	int		i;
	int		j;
	int		carry;
	int		sum;
	
	carry = 0;
	j = 0;
	num1 = add_zero_left(num2, num1);
	num2 = add_zero_left(num1, num2);
	i = ft_strlen(num1) - 1;
	if (!(out = ft_memalloc(i + 3)))
		return (NULL);
	out[i + 1] = '\0';
	while (j < ft_strlen(num1))
	{
		sum = carry + (num1[i] - '0') + (num2[i] - '0');
		if (sum >= ft_strlen(base))
		{
			out[j] = *ft_itoa(sum % 10);
			carry = base[1] - '0';
		}
		else
		{
			out[j] = *ft_itoa(sum);
			carry = base[0] - '0';
		}
		i--;
		j++;
	}
	if (carry)
		out[j] = *ft_itoa(carry);
	return (ft_strrev(out));
}

char		*multiplication(char *base, char *num1, char *num2)
{
	int		i;
	char	*mul;
	char	*sum;
	int		j;

	if (!ft_strlen(num2))
		return (num1);
	mul = "";
	sum = NULL;
	i = ft_strlen(num2) - 1;
	j = 1;
	while (i >= 0)
	{
		mul = multiply(base, num1, num2[i--]);
		mul = sum ? add_n_zero_right(mul, j++) : mul;
		sum = addition(base, sum, mul);
	}
	return (sum);
}

char		*modulos(char *base, char *num1, char *num2)
{
	char	*res;
	
	printf("div [%s]\n",  operate_division(base, num1, num2));
	printf("MUL [%s]\n",  operate_multiplication(base, num2, operate_division(base, num1, num2)));
	printf("Sub [%s]\n", operate_substraction(base, num1, operate_multiplication(base, num2, operate_division(base, num1, num2))));
	res = operate_substraction(base, num1, operate_multiplication(base, num2, operate_division(base, num1, num2)));
	printf("%s \n", res);
	
	return (NULL);
}
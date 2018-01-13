/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:28:50 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 07:45:35 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addition.h"

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
	while ((size_t)j < ft_strlen(num1))
	{
		sum = carry + (num1[i] - '0') + (num2[i] - '0');
		addition_help(base, &sum, &carry, &out[j]);
		i--;
		j++;
	}
	if (carry)
		out[j] = *ft_itoa(carry);
	return (ft_strrev(out));
}

void		addition_help(char *base, int *sum, int *carry, char *out)
{
	if ((size_t)*sum >= ft_strlen(base))
	{
		*out = *ft_itoa(*sum % 10);
		*carry = base[1] - '0';
	}
	else
	{
		*out = *ft_itoa(*sum);
		*carry = base[0] - '0';
	}
}

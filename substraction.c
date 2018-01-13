/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:31:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 04:32:41 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substraction.h"

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
			out[j] = *ft_itoa(((num1[i] - '0') + ft_strlen(base))
					- (num2[i] - '0') - borrow);
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
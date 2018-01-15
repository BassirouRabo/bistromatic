/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:33:40 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 04:10:49 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiplication.h"

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

void		initial_multiply(void)
{
	return ;	
}

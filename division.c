/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:34:44 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 04:35:32 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "division.h"

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
	return (ft_itoa(n_tm));
}
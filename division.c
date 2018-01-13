/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:34:44 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 05:44:30 by brabo-hi         ###   ########.fr       */
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

	addition_init(&n_tm, &n_sq, &cpy_num2, &num2);
	cmp = compare(base, num1, num2);
	if (cmp < 0)
		return ("0");
	if (cmp == 0)
		return ("1");
	division_help(base, &num1, &num2, &n_tm);
	n_tm = get_power(n_tm);
	tmp = num2;
	if (compare(base, num1, addition(base, num2, tmp)) >= 0)
		n_sq++;
	while (compare(base, num1, addition(base, num2, tmp)) >= 0)
	{
		n_sq++;
		num2 = addition(base, num2, tmp);
	}
	n_tm = n_tm ? n_tm * n_sq : n_sq;
	division_help2(base, &num1, &num2, &n_tm);
	return (ft_itoa(n_tm));
}

void		division_help(char *base, char **num1, char **num2, int *n_tm)
{
	while (ft_strlen(*num2) < ft_strlen(*num1) - 1)
	{
		(*n_tm)++;
		*num2 = multiplication(base, *num2, ft_itoa(ft_strlen(base)));
	}
}

void		division_help2(char *base, char **num1, char **num2, int *n_tm)
{
	while (ft_strlen(*num2) < ft_strlen(*num1) - 1)
	{
		(*n_tm)++;
		*num2 = multiplication(base, *num2, ft_itoa(ft_strlen(base)));
	}
}

void		addition_init(int *n_tm, int *n_sq, char **cpy_num2, char **num2)
{
	*n_tm = 0;
	*n_sq = 0;
	*cpy_num2 = *num2;
}

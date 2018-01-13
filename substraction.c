/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:31:43 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 07:48:00 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substraction.h"

char		*substraction(char *base, char *num1, char *num2)
{
	char	*out;
	int		i;
	int		j;
	int		borrow;

	j = 0;
	substraction_init(&num1, &num2, &borrow, &i);
	if (!(out = ft_memalloc(i + 3)))
		return (NULL);
	out[i + 1] = '\0';
	while ((size_t)j < ft_strlen(num1))
	{
		substraction_help(base,
			new_env(&num1[i], &num2[i], base), &out[j], &borrow);
		i--;
		j++;
	}
	out[j] = '\0';
	if (!ft_strcmp((const char *)num1, (const char *)num2))
		return (out);
	out = ft_strrev(out);
	return (substraction_return(base, out, borrow));
}

void		substraction_help(char *base, t_env *node, char *out, int *borrow)
{
	if (*node->num1 >= *node->num2)
	{
		*out = *ft_itoa((*node->num1 - '0') - (*node->num2 - '0') - *borrow);
		*borrow = 0;
	}
	else
	{
		*out = *ft_itoa(((*node->num1 - '0') + ft_strlen(base))
				- (*node->num2 - '0') - *borrow);
		*borrow = 1;
	}
}

void		substraction_init(char **num1, char **num2, int *borrow, int *i)
{
	*borrow = 0;
	*num1 = add_zero_left(*num2, *num1);
	*num2 = add_zero_left(*num1, *num2);
	*i = ft_strlen(*num1) - 1;
}

char		*substraction_return(char *base, char *out, int borrow)
{
	if (borrow)
		return (negative_complement(base, out));
	while (out && *out == base[0])
		out++;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:27:45 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:39:39 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char		*copy(char *str)
{
	int		i;
	char	*out;

	i = 0;
	if (!str || !(out = ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str && *str)
		out[i++] = *str++;
	out[i] = '\0';
	return (out);
}

int			compare(char *base, char *num1, char *num2)
{
	int		len_num1;
	int		len_num2;

	len_num1 = ft_strlen(num1);
	len_num2 = ft_strlen(num2);
	if (len_num1 != len_num2)
		return (len_num1 - len_num2);
	while (*num1 && *num2 && *num1 == *num2)
	{
		num1++;
		num2++;
	}
	return (get_indice(base, *num1) - get_indice(base, *num2));
}

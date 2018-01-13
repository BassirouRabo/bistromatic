/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:27:45 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 07:32:35 by brabo-hi         ###   ########.fr       */
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

t_env		*new_env(char *num1, char *num2, char *base)
{
	t_env	*node;

	node = ft_memalloc(sizeof(t_env *));
	node->num1 = ft_memalloc(ft_strlen(num1 + 1));
	node->num2 = ft_memalloc(ft_strlen(num1 + 1));
	node->base = ft_memalloc(ft_strlen(base + 1));
	node->num1 = ft_memcpy(node->num1, num1, ft_strlen(num1));
	node->num2 = ft_memcpy(node->num2, num2, ft_strlen(num2));
	node->base = ft_memcpy(node->base, base, ft_strlen(base));
	return (node);
}

t_nb		*new_nb(int *len, int *res)
{
	t_nb	*node;

	node = ft_memalloc(sizeof(t_nb *));
	node->len = ft_memalloc(sizeof(int *));
	node->res = ft_memalloc(sizeof(int *));
	node->len = len;
	node->res = res;
	return (node);
}

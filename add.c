/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:59:17 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 07:15:52 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

char		*add_negative(char *str)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = ft_memalloc(ft_strlen(str + 2))))
		return (NULL);
	out[i++] = '-';
	while (str && *str)
		out[i++] = *str++;
	return (out);
}

char		*add_zero_left(char *src, char *dest)
{
	int		i;
	char	*out;
	int		len_src;
	int		len_dest;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_src <= len_dest)
		return (dest);
	if (!(out = ft_memalloc(len_src + 1)))
		return (NULL);
	while (len_src-- > len_dest)
		out[i++] = '0';
	while (dest && *dest)
		out[i++] = *dest++;
	out[i] = '\0';
	return (out);
}

char		*add_zero_right(char *source, char *dest)
{
	int		i;
	char	*out;
	int		len_source;
	int		len_dest;

	i = 0;
	if (!source || !dest || (ft_strlen(dest) >= ft_strlen(source)))
		return (dest);
	if (!(out = ft_memalloc(ft_strlen(source + 1))))
		return (NULL);
	len_source = ft_strlen(source);
	len_dest = ft_strlen(dest);
	while (dest)
		out[i++] = *dest++;
	while (len_source-- > len_dest)
		out[i++] = '0';
	out[i] = '\0';
	return (out);
}

char		*add_n_zero_left(char *dest, int n)
{
	int		i;
	char	*out;

	if (!n || n <=0 || !dest)
		return (dest);
	i = 0;
	if (!(out = ft_memalloc(ft_strlen(dest + n + 1))))
		return (NULL);
	while (n--)
		out[i++] = '0';
	while (dest && *dest)
		out[i++] = *dest++;
	out[i] = '\0';
	return (out);
}

char		*add_n_zero_right(char *dest, int n)
{
	int		i;
	char	*out;

	if (!n || !dest)
		return (dest);
	i = 0;
	if (!(out = ft_memalloc(ft_strlen(dest + n + 1))))
		return (NULL);
	while (dest && *dest)
		out[i++] = *dest++;
	while (n--)
		out[i++] = '0';
	out[i] = '\0';
	return (out);
}

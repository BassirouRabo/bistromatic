/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:36 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 10:32:50 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "header.h"

char		get_sign(char *in);
int			get_indice(char *base, char c);
char		get_unary_sign(char *in);
int			get_power(int n);
int			is_unary(char *base, char *in);

#endif
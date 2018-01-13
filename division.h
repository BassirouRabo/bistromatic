/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:34:56 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 05:44:30 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVISION_H
# define DIVISION_H

# include "header.h"
# include "calcul.h"
# include "addition.h"
# include "substraction.h"
# include "multiplication.h"
# include "modulos.h"

char		*division(char *base, char *num1, char *num2);
void		division_help(char *base, char **num1, char **num2, int *n_tm);
void		division_help2(char *base, char **num1, char **num2, int *n_tm);
void		addition_init(int *n_tm, int *n_sq, char **cpy_num2, char **num2);

#endif

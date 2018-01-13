/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substraction.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:31:53 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 06:44:54 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTRACTION_H
# define SUBSTRACTION_H

# include "header.h"
# include "calcul.h"
# include "addition.h"
# include "multiplication.h"
# include "division.h"
# include "modulos.h"
# include "util.h"

char		*substraction(char *base, char *num1, char *num2);
void		substraction_help(char *base, t_env *node,
		char *out, int *borrow);
char		*substraction_help2(char *out, char *base);
void		substraction_init(char **num1, char **num2, int *borrow, int *i);
char		*substraction_return(char *base, char *out, int borrow);

#endif

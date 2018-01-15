/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:33:52 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 04:41:34 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIPLICATION_H
# define MULTIPLICATION_H

# include "header.h"
# include "calcul.h"
# include "addition.h"
# include "substraction.h"
# include "division.h"
# include "modulos.h"

char		*multiplication(char *base, char *num1, char *num2);
void		initial_multiply(char *num1, char **out, int *i, int *j);
void		help_multiply(char **out, int *carry, t_nb *nb, char *base);

#endif

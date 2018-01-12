/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:50:12 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 12:33:52 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "header.h"
# include "calcul.h"
# include "math.h"

char		*addition(char *base, char *num1, char *num2);
char		*substraction(char *base, char *num1, char *num2);
char		*multiplication(char *base, char *num1, char *num2);
char		*division(char *base, char *num1, char *num2);
char		*modulos(char *base, char *num1, char *num2);

#endif
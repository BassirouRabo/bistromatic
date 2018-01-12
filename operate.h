/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:00:31 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 01:48:01 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
# define OPERATE_H

# include "header.h"
# include "calcul.h"

char			*operate_addition(char *base, char *num1, char *num2);
char			*operate_substraction(char *base, char *num1, char *num2);
char			*operate_multiplication(char *base, char *num1, char *num2);
char			*operate_division(char *base, char *num1, char *num2);
char			*operate_modulos(char *base, char *num1, char *num2);

#endif
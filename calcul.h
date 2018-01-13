/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:59:28 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:58:36 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "header.h"
# include "queue.h"
# include "stack.h"
# include "helper.h"
# include "add.h"
# include "math.h"
# include "util.h"
# include "operate.h"

char		*ft_calculate(t_queue *rpn, char *base);
char		*multiply(char *base, char *num1, char num2);
char		*negative_complement(char *base, char *str);
char		*call_operation(t_stack **stack, char *base, char type);
char		*operation_addition_zero(char *base, char *num1, char *num2);

#endif

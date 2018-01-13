/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:55:32 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 03:25:18 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUNTING_H
# define SHUNTING_H

# include "header.h"
# include "queue.h"
# include "stack.h"
# include "validate.h"

int			ft_shunting(t_queue **rpn, t_queue *tk);
int			shunting_operand(t_queue **rpn, t_queue *tk);
int			shunting_operator_2(t_queue **rpn, t_queue *tk, t_stack **stack);
int			shunting_operator_1(t_queue **rpn, t_queue *tk, t_stack **stack);
int			shunting_bracket(t_queue **rpn, t_queue *tk, t_stack **stack);

#endif

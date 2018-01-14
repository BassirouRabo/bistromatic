/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 05:23:50 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 04:49:44 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "header.h"
# include "queue.h"
# include "helper.h"

int			set_operand(t_queue **head, char *base, char *in, int sign);
int			set_unary(t_queue **head, char *base, char *in);
int			set_minus(t_queue **head, char *base, char *in, char sign);
int			set_add_sub(t_queue **head, char *base, char *in);
int			set_mul_div_mod(t_queue **head, char *base, char *in);
int			set_bracket(t_queue **head, char *base, char *in);


#endif

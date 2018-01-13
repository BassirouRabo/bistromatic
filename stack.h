/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:11:29 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:53:45 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "header.h"

typedef struct      s_stack
{
    char            *data;
    enum e_type     type;
    struct s_stack  *next;
}                   t_stack;

t_stack     *stack_new(char *value, t_type type);
t_stack     *stack_push(t_stack *head, t_stack *node);
t_stack     *stack_pop(t_stack *head);
void        stack_print(t_stack *head);
int			stack_len(t_stack *head);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 07:08:22 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 07:24:56 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "header.h"
# include "stack.h"
# include "queue.h"
# include "helper.h"
# include "set.h"
# include "validate.h"

int			parse_init(char *base, char **in, t_queue **head, t_nb *nb);
int			token_operand(t_queue **head, char *base, char **in, int *len);
int			token_add_sub(t_queue **head, char **in, int *len);
int			token_mul_div_mod(t_queue **head, char *base, char **in, int *len);
int			token_braket(t_queue **head, char **in, int *len);

#endif

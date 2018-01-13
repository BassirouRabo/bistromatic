/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:07 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:28:44 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "header.h"
# include "stack.h"
# include "queue.h"
# include "helper.h"
# include "set.h"
# include "validate.h"

int			ft_parse_shunting(t_queue **rpn, t_queue *tokens);
int			ft_parse_token(t_queue **head, char *base, char *in);

#endif

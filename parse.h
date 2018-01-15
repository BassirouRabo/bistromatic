/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:07 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/15 03:01:13 by brabo-hi         ###   ########.fr       */
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
# include "token.h"
# include "util.h"

int			ft_parse_token(t_queue **head, char *base, char *in, int size);
int			set_first_sign(t_queue **head, char *base, char *in);
void		init_token(int *res, int *len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:10:44 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:11:36 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "header.h"
# include "queue.h"

int		validate_c(char *base, char *input);
int		validate_start_end(char *base, char *input);
int		validate_next(char *base, char *input);
int		valide_balance(char	*input);
int		validate_rpn(t_queue *rpn);

#endif

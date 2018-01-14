/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:59:36 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 07:16:07 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_H
# define ADD_H

# include "header.h"

char		*add_negative(char *str);
char		*add_zero_left(char *source, char *dest);
char		*add_zero_right(char *source, char *dest);
char		*add_n_zero_left(char *dest, int n);
char		*add_n_zero_right(char *dest, int n);

#endif

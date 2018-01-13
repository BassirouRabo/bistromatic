/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:18:52 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 01:20:50 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "header.h"
# include "validate.h"
# include "queue.h"
# include "parse.h"
# include "calcul.h"

int			print_error(void);
int			ft_validate(char *base, char *input);
int			print(char *str);
int			main(int argc, char **argv);
#endif

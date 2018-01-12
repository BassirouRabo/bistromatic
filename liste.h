/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:10:21 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 02:10:23 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTE_FT
# define LISTE_FT

# include "header.h"

typedef struct		s_liste
{
	char			*data;
	struct s_liste	*next;
}					t_liste;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:11:44 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 02:11:46 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
#define QUEUE_H

# include "header.h"

typedef struct 		s_queue
{
	char 			*data;
	enum e_type     type;
	struct s_queue	*next;

}					t_queue;

t_queue			*queue_new(char	*data, t_type type);
t_queue			*queue_enqueue(t_queue *head, t_queue *node);
t_queue			*queue_dequeue(t_queue *head);
void			queue_clear(t_queue *head);
void			queue_print(t_queue *head);
int				queue_len(t_queue *head);

#endif
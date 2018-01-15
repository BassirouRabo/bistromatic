/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 04:35:50 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 15:15:08 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modulos.h"

char		*modulos(char *base, char *num1, char *num2)
{	
	return (operate_substraction(base, num1,
				operate_multiplication(base, num2,
					operate_division(base, num1, num2))));
}

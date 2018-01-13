/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/13 00:48:01 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "validate.h"
#include "queue.h"
#include "parse.h"
#include "calcul.h"

int 		print_error(void)
{
	ft_putstr("syntax error\n");
	return (1);
}

int		ft_validate(char *base, char *input)
{
	if (!(validate_c(base, input)))
		return (0);
	if (!(validate_start_end(base, input)))
		return (0);
	if (!(validate_next(base, input)))
		return (0);
	if (!valide_balance(input))
		return (0);
	return (1);
}

int		print(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}

int 		main(int argc, char **argv)
{
	char 	*in;
	char 	*base;
	int		in_size;
	t_queue	*tokens;
	t_queue	*rpn;
	
	tokens = NULL;
	rpn = NULL;
	argc--;
	argv++;
	if (argc != 2)
		return (print_error());
	base = argv[0];
	in_size = ft_atoi(argv[1]);
	in_size = 12;
	if (!(in = ft_memalloc(in_size + 1)))
		return (1);
	if (read(0, in, in_size) != in_size)
		return (print_error());
	in[in_size] = '\0';
	if (!ft_validate(base, in) || !ft_parse_token(&tokens, base, in) || !ft_parse_shunting(&rpn, tokens) || !ft_parse_rpn(rpn) || !(base = ft_calculate(rpn, base)))
		return (print_error());
    return print(base);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:30:04 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/14 01:16:09 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			print_error(void)
{
	ft_putstr("syntax error\n");
	return (1);
}

int			ft_validate(char *base, char *input)
{
	if (!(validate_c(base, input)))
		return (0);
	//	printf("#\n");
	if (!(validate_start_end(base, input)))
		return (0);
//		printf("#\n");
	if (!(validate_next(base, input)))
		return (0);
	//	printf("#\n");
	if (!valide_balance(input))
		return (0);
	//	printf("#\n");
	return (1);
}

int			print(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}

int			main(int argc, char **argv)
{
	char	*in;
	char	*base;
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
	if (!(in = ft_memalloc(in_size + 1)))
		return (1);
	if (read(0, in, in_size) != in_size)
		return (print_error());
	in[in_size] = '\0';
	if (!ft_validate(base, in) || !ft_parse_token(&tokens, base, in, in_size) ||
			!ft_shunting(&rpn, tokens) || !(base = ft_calculate(rpn, base)))
		return (print_error());
	return (print(base));
}
/*
int			main(int argc, char **argv)
{
	char	*in = "2+3";
	char	*base;
	int		in_size;
	t_queue	*tokens;
	t_queue	*rpn;

	tokens = NULL;
	rpn = NULL;
	argc--;
	argv++;
	base = argv[0];z
	in_size = ft_strlen(in);
	if (!ft_validate(base, in) || !ft_parse_token(&tokens, base, in, in_size) ||
			!ft_shunting(&rpn, tokens) || !(base = ft_calculate(rpn, base)))
		return (print_error());
	return (print(base));
}
*/
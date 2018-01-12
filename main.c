/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:12:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/12 11:10:49 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "validate.h"
#include "queue.h"
#include "parse.h"
#include "calcul.h"

void 		print_error(void)
{

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
	{
		ft_putstr("Error\n");
		return (1);
	}
	base = argv[0];
	in_size = ft_atoi(argv[1]);
	if (!(in = ft_memalloc(in_size + 1)))
		return (1);
	if (read(0, in, in_size) != in_size)
	{
		ft_putstr("read error\n");
		return (1);
	}
	in[in_size] = '\0';
	if (!ft_validate(base, in))
	{
		ft_putstr("ft_validate error\n");
		ft_strdel(&in);
		return (1);
	}
	if (!ft_parse_token(&tokens, base, in))
	{
		ft_putstr("ft_parse_token error\n");
		ft_strdel(&in);
		return (1);
	}
	if (!ft_parse_shunting(&rpn, tokens))
	{
		ft_putstr("ft_parse_shunting error\n");
		ft_strdel(&in);
		queue_clear(tokens);
		return (1);
	}
	if (!ft_parse_rpn(rpn))
	{
		ft_putstr("ft_parse_rpn error\n");
		ft_strdel(&in);
		queue_clear(tokens);
	}
	if (!(base = ft_calculate(rpn, base)))
	{
		ft_putstr("ft_parse_rpn error\n");
		ft_strdel(&in);
		queue_clear(tokens);
	}
	printf("%s\n", base);
	ft_strdel(&in);
	queue_clear(tokens);
//	queue_print(rpn);
    return 0;
}
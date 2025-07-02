/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:33:47 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/02 20:07:11 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	bool			flag;
	t_stack_node	*a;
	//t_stack_node	*b;

	a = NULL;
	//b = NULL;
	flag = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split2(argv[1], ' ');
		flag = true;
	}
	if (stack_init(&a, argv + 1) == false)
	{
		if (flag)
			free_argv(argv);
		free_stack(a);
		return (1);
	}
	//stack_init(&b, "\0");
	if (flag)
		free_argv(argv);
	free_stack(a);
	//free_stack(b);
}

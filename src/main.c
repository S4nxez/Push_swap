/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:33:47 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 12:21:05 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks input and transforms it in a versatile argv
 *
 * @return 0 if argument number is not correct
 * @return 1 if ./push_swap 12 32 4
 * @return 2 if ./push_swap "12 32 4"
*/
int	parse_input(int argc, char ***argvp)
{
	char	**argv;

	argv = *argvp;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		*argvp = ft_split2(argv[1], ' ');
		return (2);
	}
	return (1);
}

void	free_stacks(t_stack_node *a, t_stack_node *b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	int				entry;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	entry = parse_input(argc, &argv);
	if (!entry)
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (stack_init(&a, argv + 1) == false)
	{
		if (entry == 2)
			free_argv(argv);
		free_stack(a);
		return (1);
	}
	calculate_chunks(&a, &b);
	if (entry == 2)
		free_argv(argv);
	free_stacks(a, b);
	return (0);
}

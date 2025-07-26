/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:12:10 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/26 18:13:47 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_stack_forward(t_stack_node *head) //TODO PARA TESTEO, ESTO SE DEJA COMENTADO
{
	while (head != NULL)
	{
		ft_printf("%d ", head->value);
		head = head->next;
	}
	ft_printf("\n");
}
*/

bool	stack_init(t_stack_node **a, char **argv)
{
	int	val;

	while (*argv)
	{
		if (!validate_number(*argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		val = ft_atol(*argv);
		if (has_reps(*a, val))
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		insert_front(a, create_node(val));
		argv++;
	}
	return (true);
}

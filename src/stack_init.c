/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:12:10 by dansanc3          #+#    #+#             */
/*   Updated: 2025/05/18 19:54:49 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_forward(t_stack_node *head) //TODO PARA TESTEO, ESTO SE DEJA COMENTADO
{
	while (head != NULL)
	{
		ft_printf("%d ", head->value);
		head = head->next;
	}
	ft_printf("\n");
}

void	stack_init(t_stack_node **a, char **argv)
{
	int	val;

	while (*argv)
	{
		val = ft_atol(*argv);
		argv++;
		if (has_reps(*a, val))
			return ;
		insert_front(a, create_node(val));
	}
	print_stack_forward(*a);
}

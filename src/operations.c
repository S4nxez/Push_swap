/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/08 19:20:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_first_and_last(t_stack_node *head,
								t_stack_node **first,
								t_stack_node **last
								)
{
	if (!head)
		return ;
	*first = head;
	while (head->next)
		head = head->next;
	*last = head;
}

/**
 * top node from stack a passes to top node of stack b
 */
void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first;

	first = *a;
	insert_front(b, first);
	*a = first->next;
}

/**
 * Top node to last position:
 * 	A B C D
 * 	B C D A
 */
void	ra(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *a;
	get_first_and_last(*a, &first, &last);
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

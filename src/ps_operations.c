/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 11:46:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Top node from stack a passes to top node of stack b
 */
void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*next_node;

	if (!a || !*a)
		return ;
	first = *a;
	next_node = first->next;
	if (next_node)
		next_node->prev = NULL;
	first->next = NULL;
	insert_front(b, first);
	*a = next_node;
	ft_printf("pb\n");
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

	if (!a || !*a || !(*a)->next)
		return ;
	get_first_and_last(*a, &first, &last);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("ra\n");
}

/**
 * Top node from stack b passes to top node of stack a
 */
void	pa(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*next_node;

	if (!b || !*b)
		return ;
	first = *b;
	next_node = first->next;
	if (next_node)
		next_node->prev = NULL;
	first->next = NULL;
	insert_front(a, first);
	*b = next_node;
	ft_printf("pa\n");
}

/**
 * Top node to last position in stack b:
 * 	A B C D
 * 	B C D A
 */
void	rb(t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	get_first_and_last(*b, &first, &last);
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("rb\n");
}

/**
 * Swap the first two elements of stack a
 */
void	sa(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*a = second;
	ft_printf("sa\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 12:03:48 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Reverse rotate stack a (last element becomes first)
 */
void	rra(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	get_first_and_last(*a, &first, &last);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = last;
	ft_printf("rra\n");
}

/**
 * Reverse rotate stack b (last element becomes first)
 */
void	rrb(t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	get_first_and_last(*b, &first, &last);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*b = last;
	ft_printf("rrb\n");
}

/**
 * Swap the first two elements of stack b
 */
void	sb(t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*b = second;
	ft_printf("sb\n");
}

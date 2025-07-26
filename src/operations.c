/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/13 19:35:19 by dansanc3         ###   ########.fr       */
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
	first = *a;
	get_first_and_last(*a, &first, &last);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("ra\n");
}

/**
 * top node from stack b passes to top node of stack a
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
 * Find the maximum value in a stack
 */
t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	int				max_value;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/**
 * Count how many rotations are needed to bring a node to the top
 */
int	count_rotations_to_top(t_stack_node *stack, t_stack_node *target)
{
	int	rotations;

	if (!stack || !target)
		return (0);
	rotations = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		rotations++;
	}
	return (rotations);
}

/**
 * Move all elements from stack B back to stack A in descending order
 */
void	return_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;
	int				rotations;

	while (*b)
	{
		max_node = find_max(*b);
		rotations = count_rotations_to_top(*b, max_node);
		while (rotations > 0)
		{
			rb(b);
			rotations--;
		}
		pa(b, a);
	}
}

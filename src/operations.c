/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 10:17:58 by dansanc3         ###   ########.fr       */
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
 * Move all elements from stack B back to stack A in ascending order
 */
void	return_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	int				rotations;
	t_stack_node	*tmp;

	while (*b)
	{
		min_node = *b;
		tmp = *b;
		while (tmp)
		{
			if (tmp->value < min_node->value)
				min_node = tmp;
			tmp = tmp->next;
		}
		rotations = count_rotations_to_top(*b, min_node);
		while (rotations > 0)
		{
			rb(b);
			rotations--;
		}
		pa(b, a);
	}
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
 * Find the position (0-based) of the minimum value in a stack
 */
int	find_min_pos(t_stack_node *stack)
{
	int				pos;
	int				min_pos;
	int				min_value;
	t_stack_node	*tmp;

	if (!stack)
		return (-1);
	pos = 0;
	min_pos = 0;
	min_value = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

